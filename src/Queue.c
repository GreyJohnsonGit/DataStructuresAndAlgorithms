#include <Queue.h>

#include <stdlib.h>

#include <Array.h>
#include <LinkedList.h>

struct Queue {
	struct LinkedList* linkedList;
};

struct Queue* Queue_create(size_t typeSize) {
	struct Queue* this = malloc(sizeof(struct Queue));
	this->linkedList = LinkedList_create(sizeof(struct Array*));
	return this;
}

void Queue_destroy(struct Queue* this) {
	struct LinkedListNode* current = LinkedList_head(this->linkedList);
	while(current != NULL) {
		Array_destroy((struct Array*)LinkedListNode_access(current));
	}
	LinkedList_destroy(this->linkedList);
	free(this);
}