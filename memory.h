#ifndef MEMORY_H
#define MEMORY_H
#define MEMORY_SIZE 100

struct memory {
  int memory[MEMORY_SIZE];
};

typedef struct Memory Memory;
typedef struct Memory * MemoryPtr;

void azzera_memory(MemoryPtr, int memory[], int size);
void memory_dump(MemoryPtr, int memory[], int size);

#endif
