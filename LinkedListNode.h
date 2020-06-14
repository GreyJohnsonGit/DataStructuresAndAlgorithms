#ifndef LinkedListNode_H_
#define LinkedListNode_H_

#include <stddef.h>

struct LinkedListNode {
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
	size_t typeSize;
	void* value;
};

void	LinkedListNode_init		(struct LinkedListNode* this, struct LinkedListNode* prev, struct LinkedListNode* next, void* value);
void	LinkedListNode_free		(struct LinkedListNode* this);
void	LinkedListNode_link		(struct LinkedListNode* previous, struct LinkedListNode* next);
void	LinkedListNode_forward	(struct LinkedListNode* this, size_t distance);
void	LinkedListNode_backward	(struct LinkedListNode* this, size_t distance);

#endif