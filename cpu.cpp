#include <iostream>
#include <iomanip>
#include "cpu.h"

using namespace std;

Cpu::Cpu(Memory* memory)
{
  reset();

	m = memory;
}

void Cpu::reset()
{
  accumulator=0;
  instructionCounter=0;
  instructionRegister=0;
  operationCode=0;
  operand=0;
}

int Cpu::get_instructionCounter()
{
  return instructionCounter;
}

int Cpu::get_operationCode()
{
  return operationCode;
}

void Cpu::incrementa_instructionCounter()
{
  instructionCounter++;
}
void Cpu::dump()
{
  cout << "Accumulator:\t\t" << showpos << setw(5) << setfill('0') << internal << accumulator <<endl << 
	"InstructionCounter:\t" << noshowpos << setw(2) << setfill('0') << instructionCounter << endl << 
	"instructionRegister:\t" << showpos << setw(5) << setfill('0') << internal <<  instructionRegister<< endl <<
	"operationCode:\t\t" << noshowpos << setw(2) << setfill('0') << operationCode << endl << 
	"operand:\t\t" << noshowpos << setw(2) << setfill('0') <<  operand << endl;
  cout << resetiosflags;
}  

void Cpu::fetch()
{
  instructionRegister = m->get(instructionCounter);
  operationCode = instructionRegister / 100;
  operand = instructionRegister % 100;		
}

void Cpu::execute()
{
  switch (operationCode) {

    case READ: 
      int value;
      cin >> value;
      m->set(operand, value);
      break;
    case WRITE: 
      cout << m->get(operand) << endl;
      break;
    case LOAD: 
      accumulator = m->get(operand);
      break;
    case STORE:
      m->set(operand, accumulator);
      break;
    case ADD: 
      accumulator+=m->get(operand);
      break;
    case SUBTRACT:
      accumulator-=m->get(operand);
      break;
    case DIVIDE: 
      accumulator/=m->get(operand);
      break;
    case MULTIPLY:
      accumulator*=m->get(operand);
      break;
    case BRANCH: 
      instructionCounter = m->get(operand);
      break;
    case BRANCHNEG:
      if (accumulator < 0) {
         instructionCounter = m->get(operand);
      }
      break;
    case BRANCHZERO:
      if (accumulator == 0) {
          instructionCounter = m->get(operand);
      }
      break;
    case HALT:
      cout << "*** Simpletron execution terminated ***" << endl;
      break; 
  }
}
