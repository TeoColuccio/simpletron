#include <iostream>

#include "simpletron.h"

using namespace std;

Simpletron::Simpletron()
{
  m = new Memory;
  c = new Cpu(m);

  c->reset();
  m->azzera();
  
	m->set(0, 1007); /* (Legge A) */
	m->set(1, 1008); /* (Legge B) */
	m->set(2, 2007); /* (Carica A nell'accumulatore) */
	m->set(3, 3008); /* (Somma B all'accumulatore) */
	m->set(4, 2109); /* (Memorizza il valore dell'accumulatore */
	m->set(5, 1109); /* (Stampa C) */
	m->set(6, 4300); /* (Halt) */
	m->set(7, 0);    /* (Variabile A) */ 
	m->set(8, 0);    /* (Variabile B) */
	m->set(9, 0);    /* (Risultato C) */	
}

void Simpletron::run()
{
   	/* il ciclo termina quando arriva l'istruzione di HALT */
 	while (c->get_operationCode()!=HALT && c->get_instructionCounter() < MEMORY_SIZE) {
 	        cout << "instructionCounter: " << c->get_instructionCounter() << endl;
		c->fetch();	
		c->incrementa_instructionCounter(); /* e' importante che l'incremento avvenga PRIMA dell'execute */
		c->execute();
	}

	/* un'unica stampa alla fine */ 
	c->dump();
	m->dump();
}

Simpletron::~Simpletron()
{
  delete c;
  delete m;
}
