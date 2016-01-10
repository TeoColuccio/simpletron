#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 100

class Memory {
  private:
	int memory[MEMORY_SIZE];

  public:
  	void set(int index, int num);
   	void azzera();
  	void dump();
};

#endif
