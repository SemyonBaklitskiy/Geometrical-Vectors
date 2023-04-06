all: start
	./start

start: main.o vectors.o
	g++ main.o vectors.o -o start

main.o: main.cpp
	g++ -Wall -Wextra -c main.cpp -o main.o

vectors.o: vectors.h vectors.cpp
	g++ -Wall -Wextra -c vectors.cpp -o vectors.o 

clean:
	rm main.o vectors.o start