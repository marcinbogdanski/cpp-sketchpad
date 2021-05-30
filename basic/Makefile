all: main

main: main.o
	g++ -ggdb -o main main.o

main.o: main.cpp
	g++ -ggdb -c main.cpp

clean:
	rm main.o main