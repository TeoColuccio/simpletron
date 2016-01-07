CFLAGS=-Wall -ansi

simpletron: main.o memory.o cpu.o
	gcc main.o memory.o cpu.o -o simpletron

main.o: main.c
memory.o: memory.c
cpu.o: cpu.c

clean:
	rm -f *.o
