#include <iostream>
#include "memory.h"

void Memory::set_memory(int index, int num)
{
 memory[index] = num;
}
void Memory::azzera_memory()
{
  int i;
  
  for (i=0; i<MEMORY_SIZE; i++) {
  	memory[i] = 0;
  }
}

void Memory::memory_dump()
{ 
  int i=0, righe=0, colonne=0;
  
  cout << "Memory: " << endl;

  putchar('\t');
  for (colonne=0;colonne<10;colonne++) {
        printf("   %d\t ",colonne);
  }
  putchar('\n');
  
  for (i=0; i<MEMORY_SIZE; i++) {
        if(i%10==0) {
                cout << righe << endl;
                righe+=10;
        }
        cout << memory[i] << endl;

        if ((i+1)%10==0) {
                putchar('\n');
        }
  }
}
