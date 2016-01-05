#include "memory.h"

void azzera_memory(int memory[], int size)
{
  int i;
  
  for (i=0; i<size; i++) {
      memory[i] = 0;
  }
}

void memory_dump(int memory[], int size)
{ 
 int i=0, righe=0, colonne=0;
  
 printf("Memory: \n");

  putchar('\t');
  for (colonne=0;colonne<10;colonne++) {
        printf("   %d\t ",colonne);
  }
  putchar('\n');
  
  for (i=0; i<size; i++) {
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


