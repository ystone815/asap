// Generator : SpinalHDL v1.10.1    git head : 2527c7c6b0fb0f95e5e1a5722a0be732b364ce43
// Component : BlinkingLed
// Git hash  : dedbab84af68fc5b4cc266d07ac7dbc69c0d2779

`timescale 1ns/1ps

module BlinkingLed (
  output wire          io_led,
  input  wire          clk,
  input  wire          reset
);

  reg        [9:0]    counter;

  assign io_led = (counter == 10'h000);
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      counter <= 10'h000;
    end else begin
      counter <= (counter + 10'h001);
    end
  end


endmodule
