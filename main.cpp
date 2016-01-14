#include <iostream>

#include "memory.h"
#include "cpu.h"

using namespace std; 

const char* welcome();

int main (){

  Simpletron s;

	m.set(0, 1007); /* (Legge A) */
	m.set(1, 1008); /* (Legge B) */
	m.set(2, 2007); /* (Carica A nell'accumulatore) */
	m.set(3, 3008); /* (Somma B all'accumulatore) */
	m.set(4, 2109); /* (Memorizza il valore dell'accumulatore */
	m.set(5, 1109); /* (Stampa C) */
	m.set(6, 4300); /* (Halt) */
	m.set(7, 0);    /* (Variabile A) */ 
	m.set(8, 0);    /* (Variabile B) */
	m.set(9, 0);    /* (Risultato C) */
	
	cout << welcome() << endl;
     
    	/* il ciclo termina quando arriva l'istruzione di HALT */
 	while (c.get_operationCode()!=HALT && c.get_instructionCounter() < MEMORY_SIZE) {
 	        cout << "instructionCounter: " << c.get_instructionCounter() << endl;
		c.fetch();	
		c.incrementa_instructionCounter(); /* e' importante che l'incremento avvenga PRIMA dell'execute */
		c.execute();
	}

	/* un'unica stampa alla fine */ 
	c.dump();
  cout << endl;
	m.dump();

	return 0;
}

const char* welcome ()
{
  return "*** Welcome to Simpletron! ***\n"
         "*** Please enter your program one istruction ***\n"
         "*** (or data word) at a time. I will type the ***\n"
         "*** location number and a question mark (?). ***\n"
         "*** You the type the word for that location. ***\n"
         "*** Type the sentinel -99999 to stop entering ***\n"
         "*** your program. ***\n";
}
