#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 100

class Memory {
  private:
	int memory[MEMORY_SIZE];

  public:
  	Memory();

	void set(int index, int num);
	int get(int index);

   	void azzera();
  	void dump();
};

#endif
