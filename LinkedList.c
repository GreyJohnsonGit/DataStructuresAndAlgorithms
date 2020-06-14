#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListNode.h"
#include "Utility.h"

void LinkedList_init(struct LinkedList* this, size_t length, size_t typeSize) {
	this->typeSize = typeSize;
	this->length = length;

	if (length == 0) {
		this->head = NULL;
		this->tail = NULL;
	}
	else {
		struct LinkedListNode* previous;
		struct LinkedListNode* current;
		
		// Create Head
		current = malloc(sizeof(struct LinkedListNode));
		LinkedListNode_init(current, NULL, NULL, malloc(typeSize));		
		this->head = current;

		// Create Trailing Nodes
		for (size_t i = 1; i < length; i++) {
			previous = current;
			current = malloc(sizeof(struct LinkedListNode));
			LinkedListNode_init(current, previous, NULL, malloc(typeSize));
			previous->next = current;
		}

		// Assign Tail
		this->tail = current;
	}
}

void LinkedList_free (struct LinkedList* this) {
	struct LinkedListNode* previous;
	struct LinkedListNode* current = this->head;

	while (current != NULL) {
		free(current->value);
		previous = current;
		current = current->next;
		free(previous);
	}
}

void	LinkedList_access	(struct LinkedList* this, size_t index, void* into) {
	struct LinkedListNode* current = this->head;

	for (size_t i = 0; i < index; i++) {
		current = current->next;
	}

	copy(into,
		current->value,
		this->typeSize);
}

void	LinkedList_assign	(struct LinkedList* this, size_t index, void* from) {
	
}

void LinkedList_print(struct LinkedList* this, void(*print)(void*)) {
	struct LinkedListNode* current = this->head;
	
	printf("HEAD -> ");
	while (current != NULL) {
		print(current->value);
		printf(" -> ");
		current = current->next;
	}
	printf("TAIL");
}