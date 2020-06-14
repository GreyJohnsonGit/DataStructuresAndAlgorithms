#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListNode.h"
#include "Utility.h"

struct LinkedList* LinkedList_init(size_t length, size_t typeSize) {
	struct LinkedList* this = malloc(sizeof(struct LinkedList));
	this->typeSize = typeSize;
	this->length = length;

	if (length == 0) {
		this->head = NULL;
		this->tail = NULL;
	}
	else {
		// Create Head
		this->head = LinkedListNode_init(this->typeSize);

		struct LinkedListNode* previous = this->head;
		struct LinkedListNode* current;

		// Create Trailing Nodes
		for (size_t i = 1; i < length; i++) {
			current = LinkedListNode_init(this->typeSize);
			LinkedListNode_link(previous, current);
			previous = current;
		}

		// Assign Tail
		this->tail = current;
	}
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

void* LinkedList_access(struct LinkedList* this, size_t index) {
	struct LinkedListNode* current = this->head;
	for (size_t i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

void LinkedList_assign	(struct LinkedList* this, size_t index, void* from) {
	struct LinkedListNode* current = this->head;
	for (size_t i = 0; i < index; i++) {
		current = current->next;
	}
	copy(current->value, from, this->typeSize);
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