package asap.tlm.base

import java.io.{BufferedWriter, File, FileWriter}
import scala.collection.mutable

/** A lightweight VCD (Value Change Dump) generator for performance simulation.
  */
object tlm_vcd_manager {
  private var writer: Option[BufferedWriter] = None
  private var startTime: Long = 0

  // Mapping: (Scope, Name) -> VCD ID
  private val signals = mutable.LinkedHashMap[(String, String), String]()
  private val values = mutable.HashMap[String, Any]() // Current values
  private var idCounter = 0

  def init(filePath: String): Unit = {
    val file = new File(filePath)
    writer = Some(new BufferedWriter(new FileWriter(file)))
    signals.clear()
    values.clear()
    idCounter = 0
    startTime = System.currentTimeMillis()
  }

  def isActive: Boolean = writer.isDefined

  def register(scope: String, name: String, width: Int): Unit = {
    if (writer.isEmpty) return
    val key = (scope, name)
    if (!signals.contains(key)) {
      val id = s"v$idCounter"
      idCounter += 1
      signals(key) = id
      values(id) = -1 // Initialize with invalid value to force first write
    }
  }

  def start(): Unit = {
    writer.foreach { w =>
      w.write(s"$$date\n  ${new java.util.Date()}\n$$end\n")
      w.write("$version\n  ASAP Perf Simulation\n$$end\n")
      w.write(
        "$timescale\n  1ns\n$$end\n"
      ) // Assuming 1 step = 1ns for simplicity

      // Group signals by scope
      val grouped = signals.keys.groupBy(_._1)

      grouped.foreach { case (scope, keys) =>
        w.write(s"$$scope module $scope $$end\n")
        keys.foreach { key =>
          val name = key._2
          val id = signals(key)
          w.write(
            s"$$var wire 32 $id $name $$end\n"
          ) // Defaulting to 32-bit wire for simplicity
        }
        w.write("$$upscope $$end\n")
      }

      w.write("$enddefinitions $end\n")
      w.write("#0\n")
      w.write("$dumpvars\n")
      // Dump initial values (0)
      signals.values.foreach { id =>
        w.write(s"b0 $id\n")
        values(id) = 0
      }
      w.write("$end\n")
    }
  }

  def log(scope: String, name: String, value: Long): Unit = {
    val id = signals.getOrElse((scope, name), return)
    val oldVal = values.getOrElse(id, -1)

    if (oldVal != value) {
      values(id) = value
    }
  }

  // Buffer for current cycle changes
  private val cycleChanges = mutable.HashMap[String, Long]()

  def update(scope: String, name: String, value: Long): Unit = {
    if (writer.isEmpty) return
    val id = signals.getOrElse((scope, name), return)
    cycleChanges(id) = value
  }

  def tick(time: Long): Unit = {
    writer.foreach { w =>
      if (cycleChanges.nonEmpty) {
        w.write(s"#$time\n")
        cycleChanges.foreach { case (id, value) =>
          w.write(s"b${value.toBinaryString} $id\n")
        }
        cycleChanges.clear()
      }
    }
  }

  def close(): Unit = {
    writer.foreach(_.close())
    writer = None
  }
}
