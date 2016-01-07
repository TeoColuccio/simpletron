#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE 100

struct Memory {
  int memory[MEMORY_SIZE];
};

typedef struct Memory Memory;
typedef struct Memory * MemoryPtr;

void set_memory(MemoryPtr m, int index, int num);
void azzera_memory(MemoryPtr m);
void memory_dump(MemoryPtr m);

#endif
