#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

struct Queue;

struct Queue* Queue_create(size_t typeSize);
void Queue_destroy(struct Queue* this);
void* Queue_peak(struct Queue* this);
void Queue_exit(struct Queue* this);
void Queue_enter(struct Queue* this, void* from);

#endif

/*
To guide function order ->
struct Stack* Stack_create(size_t typeSize);
void Stack_destroy(struct Stack* this);
void* Stack_peak(struct Stack* this);
void Stack_pop(struct Stack* this);
void Stack_push(struct Stack* this, const void* from);
size_t Stack_getLength(struct Stack* this);
size_t Stack_getTypeSize(const struct Stack* this);
void Stack_print(const struct Stack* this, void (*print)(void*));
*/