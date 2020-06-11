FLAGS = -g -std=c11
MODULE = array
MAIN = main

default: $(MAIN).o array.o linkedList.o utility.o
	gcc $(MAIN).o array.o linkedList.o utility.o -o exe

$(MAIN).o: $(MAIN).c
	gcc $(FLAGS) -c $(MAIN).c

utility.o: utility.c utility.h
	gcc $(FLAGS) -c utility.c

array.o: array.c array.h
	gcc $(FLAGS) -c array.c

linkedList.o: linkedList.c linkedList.h
	gcc $(FLAGS) -c linkedList.c

clean:
	rm -rf *.o
