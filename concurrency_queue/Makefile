all: main

main: main.o
	g++ -ggdb -o main main.o

main.o: main.cpp queue.hpp
	g++ -ggdb -c main.cpp

clean:
	rm main.o main
