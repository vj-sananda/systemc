
#include "systemc.h"

#include "memory.cpp"
#include "cpu.cpp"

#include <iostream>

int sc_main(int argc, char *argv[]) {
    // provide a memory module for the simulation system
    Memory mem("MemoryModuleA");
    CPU cpu0("CPU0");

    // linking modules
    cpu0.memory(mem);

    // also try with two CPUs (output messages jams may happen)
    //CPU cpu1("CPU1");
    //cpu1.memory(mem);

    // starting the simulation
    sc_start();
}

