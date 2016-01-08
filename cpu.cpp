#include <iostream>
#include "cpu.h"

using namespace std;

void Cpu::cpu_reset()
{
  accumulator=0;
  instructionCounter=0;
  instructionRegister=0;
  operationCode=0;
  operand=0;
}

void Cpu::cpu_dump()
{
  cout <<  accumulator  << instructionCounter << instructionRegister << operationCode << operand << endl <<;
}  

void Cpu::fetch(Memory &m)
{
  instructionRegister = (m.memory[instructionCounter]);
  operationCode = instructionRegister / 100;
  operand = instructionRegister % 100;		
}

void Cpu::execute(Memory &m)
{
  switch (operationCode) {

    case READ: 
      cin >> (m.memory[operand]);
      break;
    case WRITE: 
      printf("%d\n", m.memory[operand]);
      break;
    case LOAD: 
      accumulator = m.memory[operand];
      break;
    case STORE:
      m.memory[operand] = accumulator;
      break;
    case ADD: 
      accumulator+=m.memory[operand];
      break;
    case SUBTRACT:
      accumulator-=m.memory[operand];
      break;
    case DIVIDE: 
      accumulator/=m.memory[operand];
      break;
    case MULTIPLY:
      accumulator*=m.memory[operand];
      break;
    case BRANCH: 
      instructionCounter = m.memory[operand];
      break;
    case BRANCHNEG:
      if (accumulator < 0) {
         instructionCounter = m.memory[operand];
      }
      break;
    case BRANCHZERO:
      if (accumulator == 0) {
          instructionCounter = m.memory[operand];
      }
      break;
    case HALT:
      printf("*** Simpletron execution terminated ***\n");
      break; 
  }
}




