#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

struct Queue;

struct Queue* Queue_create(size_t typeSize);
void Queue_destroy(struct Queue* this);
void* Queue_peak(struct Queue* this);
void Queue_exit(struct Queue* this);
void Queue_enter(struct Queue* this, void* from);
size_t Queue_getLength(struct Queue* this);
size_t Queue_getTypeSize(struct Queue* this);
void Stack_print(const struct Queue* this, void (*print)(void*));

#endif