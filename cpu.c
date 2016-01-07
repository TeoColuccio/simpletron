#include <stdio.h>
#include "cpu.h"

void cpu_reset(CpuPtr c)
{
  c->accumulator=0;
  c->instructionCounter=0;
  c->instructionRegister=0;
  c->operationCode=0;
  c->operand=0;
}

void cpu_dump(CpuPtr c)
{
  printf("accumulator: +%04d\n"
      "instructionCounter: %02d\n"
      "instructionRegister: +%04d\n"
      "operationCode: %02d\n"
      "operand: %02d\n", c->accumulator, c->instructionCounter, c->instructionRegister, c->operationCode, c->operand);
}  

void fetch(MemoryPtr m, CpuPtr c)
{
  c->instructionRegister = &(m->memory[instructionCounter]);
  c->operationCode = c->instructionRegister / 100;
  c->operand = c->instructionRegister % 100;		
}

void execute(MemoryPtr m, CpuPtr)
{
  switch (c->operationCode) {

    case READ: 
      scanf("%d", &(m->memory[operand]));
      break;
    case WRITE: 
      printf("%d\n", m->memory[operand]);
      break;
    case LOAD: 
      c->accumulator = m->memory[operand];
      break;
    case STORE:
      m->memory[operand] = c->accumulator;
      break;
    case ADD: 
      c->accumulator+=m->memory[operand];
      break;
    case SUBTRACT:
      c->accumulator-=m->memory[operand];
      break;
    case DIVIDE: 
      c->accumulator/=m->memory[operand];
      break;
    case MULTIPLY:
      c->accumulator*=memory[operand];
      break;
    case BRANCH: 
      c->instructionCounter = memory[operand];
      break;
    case BRANCHNEG:
      if (accumulator < 0) {
        c->instructionCounter = memory[operand];
      }
      break;
    case BRANCHZERO:
      if (accumulator == 0) {
        c->instructionCounter = memory[operand];
      }
      break;
    case HALT:
      printf("*** Simpletron execution terminated ***\n");
      break; 
  }
}




