#include "LinkedListNode.h"

void LinkedListNode_init(struct LinkedListNode* this, struct LinkedListNode* prev, struct LinkedListNode* next, void* value) {
	this->next = next;
	this->prev = prev;
	this->value = value;
}
/*
void	LinkedListNode_free		(struct LinkedListNode* this);
void	LinkedListNode_link		(struct LinkedListNode* previous, struct LinkedListNode* next);
void	LinkedListNode_forward		(struct LinkedListNode* this, size_t distance);
void	LinkedListNode_backward	(struct LinkedListNode* this, size_t distance);
*/