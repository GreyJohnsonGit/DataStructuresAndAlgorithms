#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stddef.h>

struct LinkedListNode;

struct LinkedList {
	struct LinkedListNode* head;
	struct LinkedListNode* tail;
	size_t typeSize;
};

struct LinkedListNode {
	struct LinkedList* parent;
	struct LinkedListNode* next;
	struct LinkedListNode* prev;
	size_t typeSize;
	void* value;
};


struct LinkedListNode* LinkedListNode_init(struct LinkedList* parent);
void LinkedListNode_free(struct LinkedListNode* this);
void LinkedListNode_link(struct LinkedListNode* previous, struct LinkedListNode* next);
void* LinkedListNode_access(struct LinkedListNode* this);
struct LinkedListNode* LinkedListNode_forward(struct LinkedListNode* this, size_t distance);
struct LinkedListNode* LinkedListNode_backward(struct LinkedListNode* this, size_t distance);
struct LinkedListNode* LinkedListNode_append(struct LinkedListNode* this, const void* from);
struct LinkedListNode* LinkedListNode_prepend(struct LinkedListNode* this, const void* from);
void LinkedListNode_delete(struct LinkedListNode* this);

struct LinkedList* LinkedList_init(size_t typeSize);
void LinkedList_free(struct LinkedList* this);
void LinkedList_print(struct LinkedList* this, void(*print)(void*));
struct LinkedListNode* LinkedList_append(struct LinkedList* this, const void* from);
struct LinkedListNode* LinkedList_prepend(struct LinkedList* this, const void* from);
struct LinkedListNode* LinkedList_head(struct LinkedList* this);
struct LinkedListNode* LinkedList_tail(struct LinkedList* this);

#endif  
