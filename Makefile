CXXFLAGS=-Wall -ansi

simpletron: main.o memory.o cpu.o simpletron.o
	g++ main.o memory.o cpu.o simpletron.o -o simpletron

main.o: main.cpp
simpletron.o: simpletron.cpp
memory.o: memory.cpp
cpu.o: cpu.cpp

clean:
	rm -f *.o
