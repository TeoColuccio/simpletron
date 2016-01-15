#include <iostream>

#include "simpletron.h"

using namespace std; 

const char* welcome();

int main (){

  Simpletron s;

	cout << welcome() << endl;

  s.run();   
 
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
