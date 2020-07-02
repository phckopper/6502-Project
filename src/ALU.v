module ALU(
    // No clock needed as this is a combinatorial module
    // input wire clk;
    input wire [7:0] a_in,
    input wire [7:0] b_in,
    input wire [3:0] op,
    input wire inverted,
    input wire carry_in,

    output reg [7:0] out,
    output reg carry_out,
    output reg zero,
    output reg overflow
);

// Internal representation of each operation
// In a real 6502, each op has its own enable line
parameter SUM = 1;
parameter AND = 2;
parameter EOR = 3;
parameter OR  = 4;
parameter SR  = 5;
parameter ROR = 6;

// Allow inversion of the B input so we can support subtractions
wire [7:0] b_in_internal;
assign b_in_internal = inverted ? ~b_in : b_in;

// This will be a combinatorial only ALU
always @(*) begin
    case(op)
        SUM: {carry_out, out} = a_in + b_in_internal + {7'd0, carry_in};
        AND: out = a_in & b_in;
        EOR: out = a_in ^ b_in;
        OR:  out = a_in | b_in;
        SR:  {out, carry_out} = { 1'd0, a_in } >> 1;
        ROR: {out, carry_out} = { carry_in, a_in } >> 1;
        default: out = 0;
    endcase
end

// We overflow whenever the sign of the output is different than the ones from
// the inputs
assign overflow = (a_in[7] && b_in_internal[7] && (!out[7])) || ((!a_in[7]) && (!b_in_internal[7]) && out[7]);
assign zero = ~|out;

endmodule
