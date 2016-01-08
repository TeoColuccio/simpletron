#include <stdio.h>
#include "memory.h"
#include "cpu.h"

char* welcome();

int main (){

	Memory m;
	Cpu c;
	
	cpu_reset(&c);
	azzera_memory(&m);
	
	set_memory(&m, 0, 1007); /* (Legge A) */
	set_memory(&m, 1, 1008); /* (Legge B) */
	set_memory(&m, 2, 2007); /* (Carica A nell'accumulatore) */
	set_memory(&m, 3, 3008); /* (Somma B all'accumulatore) */
	set_memory(&m, 4, 2109); /* (Memorizza il valore dell'accumulatore */
	set_memory(&m, 5, 1109); /* (Stampa C) */
	set_memory(&m, 6, 4300); /* (Halt) */
	set_memory(&m, 7, 0);    /* (Variabile A) */ 
	set_memory(&m, 8, 0);    /* (Variabile B) */
	set_memory(&m, 9, 0);    /* (Risultato C) */
	
	printf("%s",welcome());
     
    	/* il ciclo termina quando arriva l'istruzione di HALT */
 	while (c.operationCode!=HALT && c.instructionCounter<MEMORY_SIZE) {
    printf("instructionCounter: %d\n", c.instructionCounter);
		fetch(&m, &c);	
		c.instructionCounter++; /* e' importante che l'incremento avvenga PRIMA dell'execute */
		execute(&m, &c);
	}

	/* un'unica stampa alla fine */ 
	cpu_dump(&c);
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


