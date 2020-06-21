#ifndef STACK_H_
#define STACK_H_

#include <Array.h>

#include <stddef.h>

struct Stack {
    struct Array* array;
};

struct Stack* Stack_init(size_t typeSize);
void Stack_free(struct Stack* this);
void* Stack_peak(struct Stack* this);
void Stack_pop(struct Stack* this);
void Stack_push(struct Stack* this, const void* from);
size_t Stack_getLength(struct Stack* this);
void Stack_print(const struct Stack* this, void (*print)(void*));

#endif