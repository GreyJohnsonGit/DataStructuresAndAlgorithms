#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

#include <stddef.h>

struct LinkedListNode {
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
	void* value;
};

struct LinkedListNode* LinkedListNode_init(size_t typeSize);
void LinkedListNode_free(struct LinkedListNode* this);
void LinkedListNode_link(struct LinkedListNode* previous, struct LinkedListNode* next);
struct LinkedListNode* LinkedListNode_forward(struct LinkedListNode* this, size_t distance);
struct LinkedListNode* LinkedListNode_backward(struct LinkedListNode* this, size_t distance);

#endif