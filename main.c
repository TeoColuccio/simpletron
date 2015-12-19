#include <stdio.h>

void cpu_reset(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand);
void cpu_dump(int accumulator, int instructionCounter, int  instructionRegister, int  operationCode, int operand);

int main()
{
  int accumulator, instructionCounter, instructionRegister, operationCode, operand;

  cpu_reset(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
  cpu_dump(accumulator, instructionCounter, instructionRegister, operationCode, operand);

  return 0;
}

void cpu_reset(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand)
{
  *accumulator=0;
  *instructionCounter=0;
  *instructionRegister=0;
  *operationCode=0;
  *operand=0;
}

void cpu_dump(int accumulator, int instructionCounter, int  instructionRegister, int  operationCode, int operand)
{
  printf("accumulator: +%04d\n"
      "instructionCounter: %02d\n"
      "instructionRegister: +%04d\n"
      "operationCode: %02d\n"
      "operand: %02d\n", accumulator, instructionCounter, instructionRegister, operationCode, operand);
}  
