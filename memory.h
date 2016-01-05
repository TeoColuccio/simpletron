#ifndef MEMORY_H
#define MEMORY_H
#define MEMORY_SIZE 100
struct memory {
  int memory[MEMORY_SIZE];
};

typedef struct memory memory;

void azzera_memory(int memory[], int size);
void memory_dump(int memory[], int size);

#endif
