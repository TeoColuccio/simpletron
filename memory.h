#ifndef MEMORY_H
#define MEMORY_H

struct memory {
    memory[MEMORY_SIZE];
}

typedef struct memory memory;

void azzera_memory(int memory[], int size);
void memory_dump(int memory[], int size);

#endif
