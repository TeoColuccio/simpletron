#ifndef CPU_H
#define CPU_H

#include "memory.h"

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

class Cpu { 
  private:
	int accumulator, instructionCounter, instructionRegister, operationCode, operand;
	*Memory;
  public:
	Cpu();
	void reset();
	void dump();
	void fetch();
	void execute();
};

#endif
