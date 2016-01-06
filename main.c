#include <stdio.h>
#include "memory.h"

char* welcome();

int main (){

	Memory m;
	int memory[MEMORY_SIZE];

	azzera_memory(&m, memory[]);
	
	memory[0] = 1007; /* (Legge A) */
	memory[1] = 1008; /* (Legge B) */
	memory[2] = 2007; /* (Carica A nell'accumulatore) */
	memory[3] = 3008; /* (Somma B all'accumulatore) */
	memory[4] = 2109; /* (Memorizza il valore dell'accumulatore */
	memory[5] = 1109; /* (Stampa C) */
	memory[6] = 4300; /* (Halt) */
	memory[7] = 0;    /* (Variabile A) */ 
	memory[8] = 0;    /* (Variabile B) */
	memory[9] = 0;	  /* (Risultato C) */
	
	printf("%s",welcome());
     
	memory_dump(&m, memory[]);

	return 0;
}

char* welcome ()
{
  return "*** Welcome to Simpletron! ***\n"
         "*** Please enter your program one istruction ***\n"
         "*** (or data word) at a time. I will type the ***\n"
         "*** location number and a question mark (?). ***\n"
         "*** You the type the word for that location. ***\n"
         "*** Type the sentiel -99999 to stop entering ***\n"
         "*** your program. ***\n";
}


