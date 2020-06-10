#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

struct LinkedList_Node {
    void* next;
    void* prev;
    void* value;
};

struct LinkedList {
    struct LinkedList_Node* start;
    struct LinkedList_Node* end;
    size_t length;
    size_t typeSize;
};

void    LinkedList_init    (struct LinkedList* this, size_t length, size_t typeSize);

#endif  