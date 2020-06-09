FLAGS = -g

default: main.o array.o
	gcc main.o array.o -o exe

main.o: main.c
	gcc $(FLAGS) -c main.c

array.o: array.c array.h
	gcc $(FLAGS) -c array.c

clean:
	rm -rf *.o
