#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

struct LinkedList_Node {
	struct LinkedList_Node* next;
	struct LinkedList_Node* prev;
	void* value;
};

void	_LinkedList_Node_init	(struct LinkedList_Node* this, struct LinkedList_Node* prev, struct LinkedList_Node* next, void* value);

struct LinkedList {
	struct LinkedList_Node* head;
	struct LinkedList_Node* tail;
	size_t length;
	size_t typeSize;
};


void	LinkedList_init			(struct LinkedList* this, size_t length, size_t typeSize);


#endif  