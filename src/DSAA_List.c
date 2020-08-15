#include <List.h>
#include <Utility.h>
#include <stdlib.h>

struct DSAA_ListNode {
	struct List* parent;
	struct ListNode* fore;
	struct ListNode* back;
	void* data;
};

struct DSAA_List {
	struct ListNode* head;
	struct ListNode* tail;
	size_t typeSize;
	size_t length;
};

void DSAA_ListNode_Destroy(struct ListNode* this);
void* DSAA_ListNode_Access(struct ListNode* this);
struct ListNode* DSAA_ListNode_Fore(struct ListNode* this, size_t distance);
struct ListNode* DSAA_ListNode_Back(struct ListNode* this, size_t distance);
void DSAA_ListNode_Append(struct ListNode* this, void* source);
void DSAA_ListNode_Prepend(struct ListNode* this, void* source);
struct ListNode* DSAA_ListNode_Fore_GetNext(struct ListNode* current);
struct ListNode* DSAA_ListNode_Back_GetNext(struct ListNode* current);
struct ListNode* DSAA_ListNode_Traverse(struct ListNode* this, size_t distance, struct ListNode* (*getNext)(struct ListNode* current));
struct ListNode** DSAA_ListNode_Attach_Forward(struct ListNode* this);
struct ListNode** DSAA_ListNode_Attach_Backward(struct ListNode* this);
struct ListNode** DSAA_ListNode_Attach_GetHead(struct List* this);
struct ListNode** DSAA_ListNode_Attach_GetTail(struct List* this);
struct ListNode* DSAA_ListNode_Attach(struct ListNode* this, void* source, struct ListNode**(*GetFore)(struct ListNode* this), struct ListNode**(*GetBack)(struct DSAA_ListNode* this), struct ListNode**(*GetEnd)(struct DSAA_List* this));
void DSAA_List_Destroy(struct List* this);
void DSAA_List_Foreach(struct List* this, void(*action)(void* value, void* closure), void* closure);
size_t DSAA_List_GetLength(struct List* this);
struct ListNode* DSAA_List_GetHead(struct List* this);
struct ListNode* DSAA_List_GetTail(struct List* this);
void DSAA_List_Append(struct List* this, void* source);
void DSAA_List_Prepend(struct List* this, void* source);
void DSAA_List_Attach(struct List* this, void* source, void(*Attach)(struct ListNode* this, void* source), struct ListNode*(*GetEnd)(struct List* this));


#define GetInnerNode(this) (struct DSAA_ListNode*)this->_inner
#define GetInner(this) (struct DSAA_List*)this->_inner

struct ListNode* DSAA_ListNode(struct List* parent, void* data) {
	struct DSAA_ListNode* inner = malloc(sizeof(struct DSAA_ListNode));
	inner->parent = parent;
	inner->fore = NULL;
	inner->back = NULL;
	inner->data = data;
	
	struct ListNode* this = malloc(sizeof(struct ListNode));
	this->Destroy = DSAA_ListNode_Destroy;
	this->Access = DSAA_ListNode_Access;
	this->Fore = DSAA_ListNode_Fore;
	this->Back = DSAA_ListNode_Back;
	this->Append = DSAA_ListNode_Append;
	this->Prepend = DSAA_ListNode_Prepend;
	this->_inner = inner;

	return this;
}

void DSAA_ListNode_Destroy(struct ListNode* this) {
	struct DSAA_ListNode* inner = GetInnerNode(this);
	struct DSAA_List* parentInner = GetInner(inner->parent);		
	struct ListNode* fore = this->Fore(this, 1);
	struct ListNode* back = this->Back(this, 1);
	if (fore != NULL && back != NULL) {
		struct DSAA_ListNode* foreInner = GetInnerNode(fore);
		struct DSAA_ListNode* backInner = GetInnerNode(back);
		backInner->fore = fore;
		foreInner->back = back;
		parentInner->head = NULL;
		parentInner->tail = NULL;
	}
	else if (fore != NULL) {
		struct DSAA_ListNode* foreInner = GetInnerNode(fore);
		foreInner->back = NULL;
		parentInner->head = fore;
	}
	else {
		struct DSAA_ListNode* backInner = GetInnerNode(back);
		backInner->fore = NULL;
		parentInner->tail = back;
	}
	free(inner->data);
	free(inner);
	free(this);
	parentInner->length--;
}

void* DSAA_ListNode_Access(struct ListNode* this) {
	struct DSAA_ListNode* inner = GetInnerNode(this);
	return inner->data;
}

struct ListNode* DSAA_ListNode_Fore(struct ListNode* this, size_t distance) {
	return DSAA_ListNode_Traverse(this, distance, DSAA_ListNode_Fore_GetNext);
}

struct ListNode* DSAA_ListNode_Back(struct ListNode* this, size_t distance) {
	return DSAA_ListNode_Traverse(this, distance, DSAA_ListNode_Back_GetNext);
}

void DSAA_ListNode_Append(struct ListNode* this, void* source) {
	DSAA_ListNode_Attach(this, source, DSAA_ListNode_Attach_Forward, DSAA_ListNode_Attach_Backward, DSAA_ListNode_Attach_GetTail);
}

void DSAA_ListNode_Prepend(struct ListNode* this, void* source) {
	DSAA_ListNode_Attach(this, source, DSAA_ListNode_Attach_Backward, DSAA_ListNode_Attach_Forward, DSAA_ListNode_Attach_GetHead);
}

struct ListNode* DSAA_ListNode_Fore_GetNext(struct ListNode* current) {
	return (GetInnerNode(current))->fore;
}

struct ListNode* DSAA_ListNode_Back_GetNext(struct ListNode* current) {
	return (GetInnerNode(current))->back;
}

struct ListNode* DSAA_ListNode_Traverse(struct ListNode* this, size_t distance, struct ListNode* (*getNext)(struct ListNode* current)) {
	struct ListNode* current = this;
	for(size_t i = 0; i < distance; i++) {
		current = getNext(current);
	}
	return current;
}

struct ListNode** DSAA_ListNode_Attach_Forward(struct ListNode* this) {
	struct DSAA_ListNode* inner = GetInnerNode(this);
	return &(inner->fore);
}

struct ListNode** DSAA_ListNode_Attach_Backward(struct ListNode* this) {
	struct DSAA_ListNode* inner = GetInnerNode(this);
	return &(inner->back);
}

struct ListNode** DSAA_ListNode_Attach_GetHead(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	return &(inner->head);
}

struct ListNode** DSAA_ListNode_Attach_GetTail(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	return &(inner->tail);
}

struct ListNode* DSAA_ListNode_Attach(struct ListNode* this, void* source, struct ListNode**(*GetFore)(struct ListNode* this), struct ListNode**(*GetBack)(struct DSAA_ListNode* this), struct ListNode**(*GetEnd)(struct DSAA_List* this)) {
	struct DSAA_ListNode* current = GetInnerNode(this);
	struct ListNode* new = DSAA_ListNode(current->parent, source);
	struct DSAA_ListNode* newInner = GetInnerNode(new);
	struct ListNode* fore = *GetFore(current);

	*GetBack(newInner) = this;
	*GetFore(newInner) = fore;

	*GetFore(current) = new;

	if (fore != NULL) {
		struct DSAA_ListNode* foreInner = GetInnerNode(fore);
		*GetBack(foreInner) = new;
	}
	else {
		*GetEnd(current->parent) = new;
	}

	(GetInner(current->parent))->length++;
}

struct List* DSAA_List(size_t length, size_t typeSize) {
	struct DSAA_List* inner = malloc(sizeof(DSAA_List));
	inner->head = NULL;
	inner->tail = NULL;
	inner->typeSize = typeSize;
	inner->length = 0;

	struct List* this = malloc(sizeof(struct List));
	this->Destroy = DSAA_List_Destroy;
	this->Foreach = DSAA_List_Foreach;
	this->GetLength = DSAA_List_GetLength;
	this->GetHead = DSAA_List_GetHead;
	this->GetTail = DSAA_List_GetTail;
	this->Append = DSAA_List_Append;
	this->Prepend = DSAA_List_Prepend;

	for (int i = 0; i < length; i++) {
		this->Append(this, malloc(typeSize));
	}

	return this;
}

void DSAA_List_Destroy(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	struct ListNode* head = this->GetHead(this);
	while (head != NULL) {
		head->Destroy(head);
	}
	free(inner);
	free(this);
}

void DSAA_List_Foreach(struct List* this, void(*action)(void* value, void* closure), void* closure) {
	struct ListNode* current = this->GetHead(this);
	while (current != NULL) {
		action(current->Access(current), closure);
		current = current->Fore(current, 1);
	}
}

size_t DSAA_List_GetLength(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	return inner->length;
}

struct ListNode* DSAA_List_GetHead(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	return inner->head;
}

struct ListNode* DSAA_List_GetTail(struct List* this) {
	struct DSAA_List* inner = GetInner(this);
	return inner->tail;
}

void DSAA_List_Append(struct List* this, void* source) {
	DSAA_List_Attach(this, source, DSAA_ListNode_Append, DSAA_List_GetTail);
}

void DSAA_List_Prepend(struct List* this, void* source) {
	DSAA_List_Attach(this, source, DSAA_ListNode_Prepend, DSAA_List_GetHead);
}

void DSAA_List_Attach(struct List* this, void* source, void(*Attach)(struct ListNode* this, void* source), struct ListNode*(*GetEnd)(struct List* this)) {
	struct DSAA_List* inner = GetInner(this);
	struct ListNode* end = GetEnd(this);
	void* valueCopy = malloc(inner->typeSize);
	copy(valueCopy, source, inner->typeSize);
	Attach(end, valueCopy);
}