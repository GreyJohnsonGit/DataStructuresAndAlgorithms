#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

struct LinkedListNode* LinkedListNode_init(struct LinkedList* parent) {
	struct LinkedListNode* this = malloc(sizeof(struct LinkedListNode));
	this->parent = parent;
	this->next = NULL;
	this->prev = NULL;
	this->typeSize = parent->typeSize;
	this->value = malloc(this->typeSize);
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

void* LinkedListNode_access(struct LinkedListNode* this) {
	return this->value;
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
	struct LinkedListNode* newNode = LinkedListNode_init(this->parent);
	copy(newNode->value, from, this->typeSize);
	struct LinkedListNode* afterNewNode = this->next;
	if (afterNewNode == NULL) {
		this->parent->tail = newNode;
	}
	LinkedListNode_link(this, newNode);
	LinkedListNode_link(newNode, afterNewNode);
	return newNode;
}

struct LinkedListNode* LinkedListNode_prepend(struct LinkedListNode* this, const void* from) {
	struct LinkedListNode* newNode = LinkedListNode_init(this->parent);
	copy(newNode->value, from, this->typeSize);
	struct LinkedListNode* beforeNewNode = this->prev;
	if (beforeNewNode == NULL) {
		this->parent->head = newNode;
	}
	LinkedListNode_link(beforeNewNode, newNode);
	LinkedListNode_link(newNode, this);
	return newNode;
}

void LinkedListNode_delete(struct LinkedListNode* this) {
	LinkedListNode_link(this->prev, this->next);
	if(this->prev == NULL) {
		this->parent->head = this->next;
	}
	if(this->next == NULL) {
		this->parent->tail = this->prev;
	}
	LinkedListNode_free(this);
}

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

struct LinkedListNode* LinkedList_append(struct LinkedList* this, const void* from) {
	struct LinkedListNode* newNode = LinkedListNode_init(this);	
	copy(newNode->value, from, this->typeSize);
	LinkedListNode_link(this->tail, newNode);
	this->tail = newNode;
	if (this->head == NULL) {
		this->head = newNode;
	}
	return this->tail;
}

struct LinkedListNode* LinkedList_prepend(struct LinkedList* this, const void* from) {
	struct LinkedListNode* newNode = LinkedListNode_init(this);	
	copy(newNode->value, from, this->typeSize);
	LinkedListNode_link(newNode, this->head);
	this->head = newNode;
	if (this->tail == NULL) {
		this->tail = newNode;
	}
	return this->head;
}

struct LinkedListNode* LinkedList_head(struct LinkedList* this) {
	return this->head;
}

struct LinkedListNode* LinkedList_tail(struct LinkedList* this) {
	return this->tail;
}