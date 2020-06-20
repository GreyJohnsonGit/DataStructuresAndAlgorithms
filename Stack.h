#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>
#include "Array.h"

struct Stack {
    struct Array data;
};

struct Stack* Stack_init(struct Stack* this);
void Stack_free(struct Stack* this);
void* Stack_peak(struct Stack* this);
void Stack_pop(struct Stack* this);
void Stack_push(struct Stack* this, const void* from);
size_t Stack_getLength(struct Stack* this);

#endif