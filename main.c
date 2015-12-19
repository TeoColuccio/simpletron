#include <stdio.h>

#define MEMORY_SIZE 100

char* welcome();
void azzera_memory(int memory[], int size);
void  memory_dump(int memory[], int size);

int main (){

	printf("%s",welcome());

int main()
{
	int memory[MEMORY_SIZE];

	azzera_memory(memory,MEMORY_SIZE);
	memory_dump(memory,MEMORY_SIZE);

	return 0;
}

char* welcome ()
{
  return "*** Welcome to Simpletron! ***\n"
         "*** Please enter your program one istruction ***\n"
         "*** (or data word) at a time. I will type the ***\n"
         "*** location number and a question mark (?). ***\n"
         "*** You the type the word for that location. ***\n"
         "*** Type the sentiel -99999 to stop entering ***\n"
         "*** your program. ***\n";
}

void azzera_memory(int memory[], int size)
{
	int i;

	for (i=0; i<size; i++) {
		memory[i] = 0;
	}
}

void  memory_dump(int memory[], int size)
{
	int i=0, righe=0,colonne=0;
	printf("Memory: \n");

	putchar('\t');
	for (colonne=0;colonne<10;colonne++){
		printf("   %d\t ", colonne);

	}
	putchar('\n');

	for (i=0; i<size; i++) {
		if (i%10==0) {
			printf("%2d\t", righe);
			righe+=10;
		}
		printf("+%04d\t", memory[i]);

		if ((i+1)%10==0) {
			putchar('\n');
		}
	}
}
