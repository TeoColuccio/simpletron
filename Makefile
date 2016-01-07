CFLAGS=-Wall -ansi

simpletron: main.o memory.o
	gcc main.o memory.o -o simpletron

main.o: main.c
memory.o: memory.c

clean:
	rm -f *.o
