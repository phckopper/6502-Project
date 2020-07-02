#include <stdio.h>
#include <stdlib.h>

#include "VALU.h"
#include "verilated.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    VALU *tb = new VALU;

    tb->a_in = 20;
    tb->b_in = 30;
    tb->op = 1;

    tb->eval();

    printf("Result: %d\n", tb->out);
}
