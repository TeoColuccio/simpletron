#include <stdio.h>
#include "memory.h"
void set_memory(MemoryPtr m, int index, int num)
{
  m->memory[index] = num;
}
void azzera_memory(MemoryPtr m)
{
  int i;
  
  for (i=0; i<MEMORY_SIZE; i++) {
      m->memory[i] = 0;
  }
}

void memory_dump(MemoryPtr m)
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
        printf("+%04d\t", m->memory[i]);

        if ((i+1)%10==0) {
                putchar('\n');
        }
  }
}


