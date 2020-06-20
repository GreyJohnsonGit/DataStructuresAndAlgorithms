FLAGS = -g -std=c11
ARRAYTESTS_SRC = ArrayTests.o Array.o Utility.o
LINKEDLISTTESTS_SRC = LinkedListTests.o LinkedList.o Utility.o

default: ArrayTests LinkedListTests

ArrayTests: $(ARRAYTESTS_SRC)
	gcc $(ARRAYTESTS_SRC) -o ArrayTests.go

LinkedListTests: $(LINKEDLISTTESTS_SRC)
	gcc $(LINKEDLISTTESTS_SRC) -o LinkedListTests.go

%.o: %.c
	gcc $(FLAGS) -c $<

clean:
	rm -rf *.o
	rm -rf *.go