#include "linkedList.h"

void _LinkedList_Node_init(struct LinkedList_Node* this, struct LinkedList_Node* prev, struct LinkedList_Node* next, void* value) {
	this->next = next;
	this->prev = prev;
	this->value = value;
}


void LinkedList_init (struct LinkedList* this, size_t length, size_t typeSize) {
	this->typeSize = typeSize;
	this->length = length;

	if(length == 0) {
		this->head = NULL;
		this->tail = NULL;
	}
	else {
		struct LinkedList_Node* previous;
		struct LinkedList_Node* current;
		
		// Create Head
		current = malloc(sizeof(struct LinkedList_Node));
		_LinkedList_Node_init(current, NULL, NULL, malloc(typeSize));		
		this->head = current;

		// Create Trailing Nodes
		for(size_t i = 1; i < length; i++) {
			previous = current;
			current = malloc(sizeof(struct LinkedList_Node));
			_LinkedList_Node_init(current, previous, NULL, malloc(typeSize));
			previous->next = current;
		}

		// Assign Tail
		this->tail = current;
	}
}