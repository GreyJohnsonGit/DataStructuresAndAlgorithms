#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

struct LinkedList {
	struct LinkedListNode* head;
	struct LinkedListNode* tail;
	size_t length;
	size_t typeSize;
};


struct LinkedList* LinkedList_init(size_t length, size_t typeSize);
void LinkedList_free(struct LinkedList* this);
void* LinkedList_access(struct LinkedList* this, size_t index);
void LinkedList_assign(struct LinkedList* this, size_t index, void* from);
void LinkedList_print(struct LinkedList* this, void(*print)(void*));

#endif  