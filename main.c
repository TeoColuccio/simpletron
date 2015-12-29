#include <stdio.h>

char* welcome();

int main (){

	printf("%s",welcome());

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
