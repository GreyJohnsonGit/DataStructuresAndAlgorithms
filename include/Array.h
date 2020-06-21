#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
 
struct Array;

struct Array* Array_create(size_t length, size_t typeSize);
void Array_destroy(struct Array* this);
void* Array_access(const struct Array* this, size_t index);
void Array_delete(struct Array* this, size_t index);
void Array_insert(struct Array* this, size_t index, const void* from);
size_t Array_getLength(const struct Array* this);
size_t Array_getTypeSize(const struct Array* this);
void Array_resize(struct Array* this, size_t newLength);
void Array_print(const struct Array* this, void (*print)(void*));

#endif
