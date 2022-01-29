all: server

server: server.o
	g++ -ggdb -o server server.o

server.o: server.cpp
	g++ -ggdb -c server.cpp

clean:
	rm server.o server