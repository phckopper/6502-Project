#include <stdio.h>
#include <stdlib.h>

#include "VALU.h"
#include "verilated.h"

void test_adder(VALU *tb) {
    tb->op = 1; // ADD internal representation

    // We loop across every possible input to find errors
    // This will be substituted by formal verification along the way
    for(int a = 0; a < 256; a++) {
        for(int b = 0; b < 256; b++) {
            tb->carry_in = 0; // start with a clear carry in
            tb->a_in = a; tb->b_in = b; // We populate our inputs

            tb->eval(); // simulate!

            // Calculate correct values in C so we can compare them
            int golden = a + b;
            bool correct_out = (tb->out == (golden & 0xff));
            bool correct_flags = (tb->carry_out == (golden > 0xff));

            if(!correct_out || !correct_flags) {
                printf("A: %d B: %d Out: %s Flags: %s\n", a, b, correct_out ? "CORRECT" : "WRONG", correct_flags ? "CORRECT" : "WRONG");
                printf("Out: %d\n", tb->out);
                printf("Test stopped! Wrong answers!");
                return;
            }
        }
    }
    printf("Adder working correctly!\n");
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    VALU *tb = new VALU;
    test_adder(tb);

}
