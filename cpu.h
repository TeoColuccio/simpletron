#ifndef CPU_H
#define CPU_H

#include "memory.h"

#define MEMORY_SIZE 100
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

struct cpu { 
	int accumulator, instructionCounter, instructionRegister, operationCode, operand;
};

typedef struct cpu Cpu;
typedef struct cpu * CpuPtr;

void cpu_reset(CpuPtr c);
void cpu_dump(CpuPtr c);
void fetch(MemoryPtr m, CpuPtr c);
void execute(MemoryPtr m, CpuPtr);

#endif
