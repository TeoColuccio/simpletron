CXXFLAGS=-Wall -ansi

simpletron: main.o memory.o cpu.o
	g++ main.o memory.o cpu.o -o simpletron

main.o: main.cpp
memory.o: memory.cpp
cpu.o: cpu.cpp

clean:
	rm -f *.o
