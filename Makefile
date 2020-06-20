FLAGS = -g -std=c11
CC = gcc
ARRAYTESTS_SRC = ArrayTests.o Array.o Utility.o
LINKEDLISTTESTS_SRC = LinkedListTests.o LinkedList.o Utility.o
STACKTESTS_SRC = StackTests.o Stack.o Array.o Utility.o

default: ArrayTests LinkedListTests StackTests

ArrayTests: $(ARRAYTESTS_SRC)
	$(CC) $(ARRAYTESTS_SRC) -o ArrayTests.go

LinkedListTests: $(LINKEDLISTTESTS_SRC)
	$(CC) $(FLAGS) $(LINKEDLISTTESTS_SRC) -o LinkedListTests.go

StackTests: $(STACKTESTS_SRC)
	$(CC) $(FLAGS) $(STACKTESTS_SRC) -o StackTests.go

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -rf *.o
	rm -rf *.go