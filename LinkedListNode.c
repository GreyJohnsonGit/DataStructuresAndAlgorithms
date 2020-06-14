#include "LinkedListNode.h"

#include <stdlib.h>

struct LinkedListNode* LinkedListNode_init(size_t typeSize) {
	struct LinkedListNode* this = malloc(sizeof(struct LinkedListNode));
	this->next = NULL;
	this->prev = NULL;
	this->value = malloc(typeSize);
	return this;
}

void LinkedListNode_free(struct LinkedListNode* this) {
	free(this->value);
	free(this);
}

void LinkedListNode_link(struct LinkedListNode* previous, struct LinkedListNode* next) {
	previous->next = next;
	next->prev = previous;
}

struct LinkedListNode* LinkedListNode_forward(struct LinkedListNode* this, size_t distance) {
	struct LinkedListNode* current = this;
	for (size_t i = 0; i < distance; i++) {
		current = current->next;
	}
	return current;
}

struct LinkedListNode* LinkedListNode_backward(struct LinkedListNode* this, size_t distance) {
	struct LinkedListNode* current = this;
	for (size_t i = 0; i < distance; i++) {
		current = current->prev;
	}
	return current;
}