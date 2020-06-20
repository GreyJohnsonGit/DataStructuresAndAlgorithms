#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

struct LinkedListNode* LinkedListNode_init(size_t typeSize) {
	struct LinkedListNode* this = malloc(sizeof(struct LinkedListNode));
	this->next = NULL;
	this->prev = NULL;
	this->typeSize = typeSize;
	this->value = malloc(typeSize);
	return this;
}

void LinkedListNode_free(struct LinkedListNode* this) {
	free(this->value);
	free(this);
}

void LinkedListNode_link(struct LinkedListNode* previous, struct LinkedListNode* next) {
	if(previous != NULL) {
		previous->next = next;
	}
	if(next != NULL) {
		next->prev = previous;
	}
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

struct LinkedListNode* LinkedListNode_append(struct LinkedListNode* this, const void* from) {
	struct LinkedListNode* newNode = LinkedList_init(this->typeSize);
	struct LinkedListNode* afterNewNode = this->next;
	LinkedListNode_link(this, newNode);
	LinkedListNode_link(newNode, afterNewNode);
	return newNode;
}

struct LinkedListNode* LinkedListNode_prepend(struct LinkedListNode* this, const void* from) {
	struct LinkedListNode* newNode = LinkedList_init(this->typeSize);
	struct LinkedListNode* beforeNewNode = this->prev;
	LinkedListNode_link(beforeNewNode, newNode);
	LinkedListNode_link(newNode, this);
	return newNode;
}
// void LinkedListNode_delete(struct LinkedListNode* this)

struct LinkedList* LinkedList_init(size_t typeSize) {
	struct LinkedList* this = malloc(sizeof(struct LinkedList));
	this->typeSize = typeSize;
	this->head = NULL;
	this->tail = NULL;
	return this;
}

void LinkedList_free(struct LinkedList* this) {
	struct LinkedListNode* current = this->head;
	struct LinkedListNode* next;

	while (current != NULL) {
		next = current->next;
		LinkedListNode_free(current);
		current = next;
	}
}

void LinkedList_print(struct LinkedList* this, void(*print)(void*)) {
	struct LinkedListNode* current = this->head;
	
	printf("HEAD -> ");
	while (current != NULL) {
		print(current->value);
		printf(" -> ");
		current = current->next;
	}
	printf("TAIL\n");
}

// struct LinkedListNode* LinkedList_append(struct LinkedList* this, const void* from);
// struct LinkedListNode* LinkedList_prepend(struct LinkedList* this, const void* from);