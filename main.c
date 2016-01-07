#include <stdio.h>
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

char* welcome();
void cpu_reset(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand);
void cpu_dump(int accumulator, int instructionCounter, int  instructionRegister,int operationCode, int operand);
void fetch(MemoryPtr m, int instructionCounter, int *instructionRegister, int *operationCode, int *operand);
void execute(MemoryPtr m, int *instructionCounter , int instructionRegister, int operationCode, int operand, int *accumulator);

int main (){

	Memory m;
	int accumulator, instructionCounter, instructionRegister, operationCode, operand;
	
	cpu_reset(&accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
	azzera_memory(&m);
	
	m.memory[0] = 1007; /* (Legge A) */
	m.memory[1] = 1008; /* (Legge B) */
	m.memory[2] = 2007; /* (Carica A nell'accumulatore) */
	m.memory[3] = 3008; /* (Somma B all'accumulatore) */
	m.memory[4] = 2109; /* (Memorizza il valore dell'accumulatore */
	m.memory[5] = 1109; /* (Stampa C) */
	m.memory[6] = 4300; /* (Halt) */
	m.memory[7] = 0;    /* (Variabile A) */ 
	m.memory[8] = 0;    /* (Variabile B) */
	m.memory[9] = 0;	  /* (Risultato C) */
	
	printf("%s",welcome());
     
     	/* il ciclo termina quando arriva l'istruzione di HALT */
 	while (operationCode!=HALT && instructionCounter<MEMORY_SIZE) {
    printf("instructionCounter: %d\n", instructionCounter);
		fetch(&m, instructionCounter, &instructionRegister, &operationCode, &operand);	
		instructionCounter++; /* e' importante che l'incremento avvenga PRIMA dell'execute */
		execute(&m, &instructionCounter, instructionRegister, operationCode, operand, &accumulator);
	}

	/* un'unica stampa alla fine */
	cpu_dump(accumulator, instructionCounter, instructionRegister, operationCode, operand);
	memory_dump(&m);

	return 0;
}

char* welcome ()
{
  return "*** Welcome to Simpletron! ***\n"
         "*** Please enter your program one istruction ***\n"
         "*** (or data word) at a time. I will type the ***\n"
         "*** location number and a question mark (?). ***\n"
         "*** You the type the word for that location. ***\n"
         "*** Type the sentinel -99999 to stop entering ***\n"
         "*** your program. ***\n";
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

void fetch(MemoryPtr m, int instructionCounter, int *instructionRegister, int *operationCode, int *operand)
{
	*instructionRegister = m->memory[instructionCounter];
	*operationCode = *instructionRegister / 100;
	*operand = *instructionRegister % 100;		
}

void execute(MemoryPtr m, int *instructionCounter , int instructionRegister, int operationCode, int operand, int *accumulator)
{
	switch (operationCode) {

	case READ: 
		 scanf("%d", &(m->memory[operand]));
		break;
	case WRITE: 
		printf("%d\n", m->memory[operand]);
		break;
	case LOAD: 
		*accumulator = m->memory[operand];
		break;
	case STORE:
		m->memory[operand] = *accumulator;
		break;
	case ADD: 
		*accumulator+=m->memory[operand];
		break;
	case SUBTRACT:
		*accumulator-=m->memory[operand];
		break;
	case DIVIDE: 
		*accumulator/=m->memory[operand];
		break;
	case MULTIPLY:
		*accumulator*=m->memory[operand];
		break;
	case BRANCH: 
		*instructionCounter = m->memory[operand];
		break;
	case BRANCHNEG:
		if (accumulator < 0) {
		*instructionCounter = m->memory[operand];
		}
		break;
	case BRANCHZERO:
		if (accumulator == 0) {
		*instructionCounter = m->memory[operand];
		}
		break;
	case HALT:
		printf("*** Simpletron execution terminated ***\n");
		break; 
	}
}
