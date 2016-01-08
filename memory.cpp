#include <stdio.h>
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
  
  printf("Memory: \n");

  putchar('\t');
  for (colonne=0;colonne<10;colonne++) {
        printf("   %d\t ",colonne);
  }
  putchar('\n');
  
  for (i=0; i<MEMORY_SIZE; i++) {
        if(i%10==0) {
                printf("%2d\t",righe);
                righe+=10;
        }
        printf("+%04d\t", memory[i]);

        if ((i+1)%10==0) {
                putchar('\n');
        }
  }
}
