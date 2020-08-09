#include <Queue.h>

#include <stdio.h>

void TEST_Queue() {
    struct Queue* queue = Queue_create(sizeof(char));

    Queue_destroy(queue);
    printf("I ran!\n");
}