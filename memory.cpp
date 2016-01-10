#include <iostream>
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

  cout <<'\t';
  for (colonne=0;colonne<10;colonne++) {
        cout << colonne << '\t';
  }
  cout <<'\n';
  
  for (i=0; i<MEMORY_SIZE; i++) {
        if(i%10==0) {
                cout << righe << endl;
                righe+=10;
        }
        cout << memory[i] << endl;

        if ((i+1)%10==0) {
                cout <<'\n';
        }
  }
}
