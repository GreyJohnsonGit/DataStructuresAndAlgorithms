FLAGS = -g -std=c11
EXE = exe

ArrayTests: ArrayTests.o Array.o Utility.o
	gcc ArrayTests.o Array.o Utility.o -o $(EXE)

linkedListTests: LinkedListTests.o LinkedList.o LinkedListNode.o Utility.o
	gcc LinkedListTests.o LinkedList.o LinkedListNode.o Utility.o -o $(EXE)

Array.o: Array.c
	gcc $(FLAGS) -c Array.c

ArrayTests.o: ArrayTests.c
	gcc $(FLAGS) -c ArrayTests.c

LinkedList.o: LinkedList.c
	gcc $(FLAGS) -c LinkedList.c

LinkedListNode.o: LinkedListNode.c
	gcc $(FLAGS) -c LinkedListNode.c

LinkedListTests.o: LinkedListTests.c
	gcc $(FLAGS) -c LinkedListTests.c

Utility.o: Utility.c
	gcc $(FLAGS) -c Utility.c

clean:
	rm -rf *.o
	rm $(EXE)