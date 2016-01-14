#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include "memory.h"
#include "cpu.h"

class Simpletron {
  private:
    Cpu* c;
    Memory* m;
  public:
    simpletron();
    run();
    ~simpletron();
}

#endif
