#include <Array.h>

#include <Utility.h>

#include <stdio.h>
#include <stdlib.h>

#define RESIZE_CONSTANT 2

struct Array {
	void* data;
	size_t typeSize;
	size_t size;
	size_t length;
};

struct Array* Array_create(size_t length, size_t typeSize) {
	struct Array* this = malloc(sizeof(struct Array));
	this->typeSize = typeSize;
	this->size = 1;
	this->data = malloc(typeSize);
	Array_resize(this, length);
	return this;
}

void Array_destroy(struct Array* this) {
	free(this->data);
	this->data = NULL;
}

void* Array_access(const struct Array* this, size_t index) {
	return ((char*)this->data + (index * this->typeSize));
}

void Array_delete(struct Array* this, size_t index) {
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

size_t Array_getTypeSize(const struct Array* this) {
	return this->typeSize;
}

void Array_resize(struct Array* this, size_t newLength) {
	if (newLength > this->size) {
		for (; newLength > this->size; this->size = (size_t)(this->size * RESIZE_CONSTANT + 0.5f));
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

void Array_Hello(const struct Array* this) {
	printf("Hello There");
}