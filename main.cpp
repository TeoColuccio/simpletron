#include <iostream>

#include "memory.h"
#include "cpu.h"

using namespace std; 

char* welcome();

int main (){

	Memory m;
	Cpu c;
	
	c.cpu_reset(&c);
	m.azzera_memory(&m);
	
	m.set_memory(&m, 0, 1007); /* (Legge A) */
	m.set_memory(&m, 1, 1008); /* (Legge B) */
	m.set_memory(&m, 2, 2007); /* (Carica A nell'accumulatore) */
	m.set_memory(&m, 3, 3008); /* (Somma B all'accumulatore) */
	m.set_memory(&m, 4, 2109); /* (Memorizza il valore dell'accumulatore */
	m.set_memory(&m, 5, 1109); /* (Stampa C) */
	m.set_memory(&m, 6, 4300); /* (Halt) */
	m.set_memory(&m, 7, 0);    /* (Variabile A) */ 
	m.set_memory(&m, 8, 0);    /* (Variabile B) */
	m.set_memory(&m, 9, 0);    /* (Risultato C) */
	
	cout << welcome()<< endl;
     
    	/* il ciclo termina quando arriva l'istruzione di HALT */
 	while (c.operationCode!=HALT && c.instructionCounter<MEMORY_SIZE) {
    cout << "instructionCounter: " << c.instructionCounter << endl;
		c.fetch(&c);	
		c.instructionCounter++; /* e' importante che l'incremento avvenga PRIMA dell'execute */
		c.execute(&c);
	}

	/* un'unica stampa alla fine */ 
	c.cpu_dump(&c);
	m.memory_dump(&m);

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
