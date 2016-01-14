#include <iostream>

#include "simpletron.h"

using namespace std;

Simpletron::simpletron()
{
  m = new Memory;
  c = new Cpu;

  reset();
  azzera();
}

void Simpletron::run()
{
}

Simpletron::~simpletron()
{
  delete c;
  delete m;
}
