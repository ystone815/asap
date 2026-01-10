import simpy
import time

# Configuration matching Scala perf_stress_test
PACKET_COUNT = 500000
LATENCY = 5  # 5 ps (Wait, Scala used 5ns? No, Scala used 5 in code comment say 5ns?
# Let's check Scala code: val latencyVal = 5 // 5ns
# And Generator period = 1000.
# So if 1 unit = 1ps.
# Generator period = 1000ps = 1ns.
# Latency = 5 units = 5ps?
# In perf_delay_line.scala: sleep(latency).
# So simply 5ps. The comment "5ns" in Scala might be misleading or I misread 5 as 5000.
# Step 707 Scala code: `val latencyVal = 5 // 5ns`.
# If unit is 1ps, then 5 is 5ps.
# But Generator period is 1000.
# Let's match exact values.
# LATENCY = 5
# GENERATOR_PERIOD = 1000.

LATENCY = 5
GENERATOR_PERIOD = 1000
CAPACITY = 1000

class Packet:
    def __init__(self, id, created_at):
        self.id = id
        self.created_at = created_at

def packet_generator(env, out_pipe):
    """Generates packets every GENERATOR_PERIOD."""
    i = 0
    # Simulating 1.0 rate (every cycle/period)
    while True:
        yield env.timeout(GENERATOR_PERIOD)
        pkt = Packet(i, env.now)
        yield out_pipe.put(pkt)
        i += 1
        # In Scala, we generated a packet then waited?
        # Scala: if(rand < rate) write; waitSampling().
        # waitSampling(1000) corresponds to env.timeout(1000).
        # We assume full rate 1.0.

def delay_line(env, in_pipe, out_pipe, latency, name):
    """Reads from in_pipe, waits, writes to out_pipe."""
    while True:
        pkt = yield in_pipe.get()
        if latency > 0:
            yield env.timeout(latency)
        yield out_pipe.put(pkt)

def sink(env, in_pipe):
    """Consumes packets until PACKET_COUNT is reached."""
    count = 0
    while count < PACKET_COUNT:
        pkt = yield in_pipe.get()
        count += 1
    return count

def run_sim():
    env = simpy.Environment()
    
    # Create Queues (SimPy Strings/Stores)
    # 5 Stages -> 6 Queues (Q0...Q5)
    stages = 5
    queues = [simpy.Store(env, capacity=CAPACITY) for _ in range(stages + 1)]
    
    # Instantiate Components
    # Generator -> Q0
    env.process(packet_generator(env, queues[0]))
    
    # Delay Lines: Q(i) -> Delay -> Q(i+1)
    for i in range(stages):
        env.process(delay_line(env, queues[i], queues[i+1], LATENCY, i))
        
    # Sink -> Q(last)
    # We need to track when sink finishes.
    # In SimPy, we can't easily wait on a process return value in main unless we wrap it.
    
    # To measure time, we just run env.run(). But we need a stop condition.
    # We can pass an event/process to env.run()
    
    sink_proc = env.process(sink(env, queues[-1]))
    
    print(f"=== SimPy Stress Test ({PACKET_COUNT} packets) ===")
    print("Simulation started...")
    
    start_time_real = time.time()
    
    env.run(until=sink_proc)
    
    end_time_real = time.time()
    
    wall_time = end_time_real - start_time_real
    sim_time = env.now
    
    print("\n--- SimPy Stress Test Results ---")
    print(f"Total Packets: {PACKET_COUNT}")
    print(f"Sim Time:      {sim_time} ps")
    print(f"Wall Time:     {wall_time * 1000:.2f} ms")
    
    if wall_time > 0:
        pps = PACKET_COUNT / wall_time
        print(f"Sim Speed:     {pps:.2f} packets/sec")
        
    if sim_time > 0:
        # 1e12 ps = 1s
        bw = (PACKET_COUNT * 1e12) / sim_time
        print(f"Model BW:      {bw:.2f} packets/sec")
        print(f"               {bw/1e9:.2f} Gpps")

if __name__ == "__main__":
    run_sim()
