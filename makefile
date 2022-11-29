CC = gcc

FLAGS = -Wall -g

all: main

main: main.o my_mat.o
	$(CC) $(FLAGS) my_mat.c my_mat.h main.c -o connections

main.o: main.c
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean:
	rm -f *.a *.so *.o connections

.PHONY:
	clean all