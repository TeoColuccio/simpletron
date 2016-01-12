#include <iostream>
#include <iomanip>
#include "memory.h"

using namespace std;

Memory::Memory()
{
	azzera();
}

void Memory::set(int index, int num)
{
	memory[index] = num;
}

int Memory::get(int index)
{
	return memory[index];
}

void Memory::azzera()
{
	int i;

	for (i=0; i<MEMORY_SIZE; i++) {
		memory[i] = 0;
	}
}

void Memory::dump()
{ 
	int i=0, righe=0, colonne=0;

	cout << "Memory: " << endl;

	cout << '\t';
	for (colonne=0; colonne<10; colonne++) {
		cout << colonne << '\t';
	}
	cout << endl;

	for (i=0; i<MEMORY_SIZE; i++) {
		if(i%10==0) {
			cout << setw(2) << righe << '\t';
			righe+=10;
		}
		cout << setw(5) << showpos << setfill('0') << internal << memory[i] << '\t';

		if ((i+1)%10==0) {
			cout << endl;
		}
	}
  cout << resetiosflags;
}
