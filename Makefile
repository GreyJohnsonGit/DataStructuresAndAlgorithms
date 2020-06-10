FLAGS = -g -std=c11
MODULE = linkedList

default: main.o $(MODULE).o
	gcc main.o $(MODULE).o -o exe

main.o: main.c
	gcc $(FLAGS) -c main.c

$(MODULE).o: $(MODULE).c $(MODULE).h
	gcc $(FLAGS) -c $(MODULE).c

clean:
	rm -rf *.o
