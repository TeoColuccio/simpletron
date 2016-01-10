#include <iostream>
#include "cpu.h"

using namespace std;

void Cpu::reset()
{
  accumulator=0;
  instructionCounter=0;
  instructionRegister=0;
  operationCode=0;
  operand=0;
}

void Cpu::dump()
{
  cout << "Accumulator: " <<  accumulator <<endl << 
       		"InstructionCounter: " << instructionCounter << endl << 
			"instructionRegister: " <<  instructionRegister<< endl <<
				"operationCode: " <<  operationCode << endl << 
					"operand: " <<  operand << endl;
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
      cout << m.memory[operand] << endl;
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
      cout << "*** Simpletron execution terminated ***" << endl;
      break; 
  }
}




