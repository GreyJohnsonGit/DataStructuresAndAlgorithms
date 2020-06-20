#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Utility.h"

struct Array* Array_init(size_t length, size_t typeSize) {
	struct Array* this = malloc(sizeof(struct Array));
	this->typeSize = typeSize;
	this->size = 1;
	this->data = malloc(typeSize);
	Array_resize(this, length);
	return this;
}

void Array_free(struct Array* this) {
	free(this->data);
	this->data = NULL;
}

void* Array_access(const struct Array* this, size_t index) {
	return ((char*)this->data + (index * this->typeSize));
}

void Array_delete(struct Array* this, size_t index) {
	// Deletes element then shifts elements to fill the gap
	for (size_t i = index; i < this->length - 1; i++) {
		copy(Array_access(this, i), Array_access(this, i + 1), this->typeSize);
	}
	Array_resize(this, this->length - 1);
}

void Array_insert(struct Array* this, size_t index, const void* from) {
	Array_resize(this, this->length + 1);
	for (size_t i = this->length - 1; i > index; i--) {
		copy(Array_access(this, i), Array_access(this, i - 1), this->typeSize);
	}
	copy(Array_access(this, index), from, this->typeSize);
}

size_t Array_getLength(const struct Array* this) {
	return this->length;
}

void Array_resize(struct Array* this, size_t newLength) {
	if (newLength > this->size) {
		// Doubles in size until $this->size can contain $newLength
		for (this->size; newLength > this->size; this->size *= 2);
		this->data = realloc(this->data, this->typeSize * this->size);
	}
	this->length = newLength;
}

void Array_print(const struct Array* this, void (*print)(void*)) {
	for (size_t i = 0; i < this->length; i++) {
		printf("[%lu]: ", i);
		print((void*)((char*)this->data + (i * this->typeSize)));
		printf("\n");
	}
}