#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 100

class Memory {
  private:
	int memory[MEMORY_SIZE];

  public:
  	void set_memory(int index, int num);
   	void azzera_memory();
  	void memory_dump();
};

#endif
