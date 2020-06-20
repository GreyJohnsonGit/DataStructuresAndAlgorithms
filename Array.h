#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
 
struct Array {
	void* data;
	size_t typeSize;
	size_t size;
	size_t length;
};

struct Array* Array_init(size_t length, size_t typeSize);
void Array_free(struct Array* this);
void* Array_access(const struct Array* this, size_t index);
void Array_delete(struct Array* this, size_t index);
void Array_insert(struct Array* this, size_t index, const void* from);
size_t Array_getLength(const struct Array* this);
void* Array_peak(const struct Array* this);
void Array_pop(struct Array* this);
void Array_push(struct Array* this, const void* from);
void Array_resize(struct Array* this, size_t newLength);
void Array_print(const struct Array* this, void (*print)(void*));

#endif
