#include <Stack.h>

#include <Array.h>

#include <stdlib.h>

struct Stack {
    struct Array* array;
};

struct Stack* Stack_create(size_t typeSize) {
    struct Stack* this = malloc(sizeof(struct Stack));
    this->array = Array_create(0, typeSize);
    return this;
}

void Stack_destroy(struct Stack* this) {
    Array_destroy(this->array);
    free(this);
}

void* Stack_peak(struct Stack* this) {
    return Array_access(this->array, Array_getLength(this->array) - 1);
}

void Stack_pop(struct Stack* this) {
    Array_delete(this->array, Array_getLength(this->array) - 1);
}

void Stack_push(struct Stack* this, const void* from) {
    Array_insert(this->array, Array_getLength(this->array), from);
}

size_t Stack_getLength(struct Stack* this) {
    return Array_getLength(this->array);
}

size_t Stack_getTypeSize(const struct Stack* this) {
    return Array_getTypeSize(this->array);
}

void Stack_print(const struct Stack* this, void (*print)(void*)) {
    Array_print(this->array, print);
}