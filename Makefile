FLAGS = -g -std=c11

default: ArrayTests LinkedListTests

ArrayTests: ArrayTests.o Array.o Utility.o
	gcc ArrayTests.o Array.o Utility.o -o ArrayTests.go

LinkedListTests: LinkedListTests.o LinkedList.o Utility.o
	gcc LinkedListTests.o LinkedList.o Utility.o -o LinkedListTests.go

Array.o: Array.c
	gcc $(FLAGS) -c Array.c

ArrayTests.o: ArrayTests.c
	gcc $(FLAGS) -c ArrayTests.c

LinkedList.o: LinkedList.c
	gcc $(FLAGS) -c LinkedList.c

LinkedListTests.o: LinkedListTests.c
	gcc $(FLAGS) -c LinkedListTests.c

Utility.o: Utility.c
	gcc $(FLAGS) -c Utility.c

clean:
	rm -rf *.o
	rm -rf *.go