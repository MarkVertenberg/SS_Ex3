CC=gcc
FLAGS = -Wall -g

all: stringProg

stringProg: main.o 
	$(CC) $(FLAGS) -o stringProg main.o

main.o: main.c 
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg