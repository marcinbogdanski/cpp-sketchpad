all: main

main: main.o
	g++ --std=c++17 -ggdb -o main main.o

main.o: main.cpp
	g++ --std=c++17 -ggdb -c main.cpp

clean:
	rm main.o main