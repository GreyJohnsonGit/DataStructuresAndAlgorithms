#include "array.h"

void Array_init(struct Array* this, size_t length, size_t typeSize) {
	this->typeSize = typeSize;
	this->size = 1;
	this->data = malloc(typeSize);
	Array_resize(this, length);
}

void Array_free(struct Array* this) {
	free(this->data);
	this->data = NULL;
}

void Array_access(const struct Array* this, size_t index, void* into) {
	copyElement(into,
		(void*)((char*)this->data + (index * this->typeSize)),
		this->typeSize);
}

void Array_assign(struct Array* this, size_t index, const void* from) {
	copyElement((void*)((char*)this->data + (index * this->typeSize)),
		from,
		this->typeSize);
}

void Array_delete(struct Array* this, size_t index) {
	// Deletes element then shifts elements to fill the gap
	for(index; index < this->length - 1; index++) {
		void* nextElement = malloc(this->typeSize);
		Array_access(this, index + 1, nextElement);
		Array_assign(this, index, nextElement);
		free(nextElement);
	}
	this->length--;
}

size_t Array_getSize(const struct Array* this) {
	return this->size;
}

size_t Array_getLength(const struct Array* this) {
	return this->length;
}	

void Array_pop(struct Array* this, void* into) {
	Array_access(this, this->length - 1, into);
	this->length--;
}

void Array_push(struct Array* this, const void* from) {
	// Expand to fit new element
	if(this->length == this->size) Array_resize(this, this->length + 1);
	else this->length++;
	Array_assign(this, this->length - 1, from);
}

void Array_resize(struct Array* this, size_t newLength) {
	// Doubles in size until $this can contain $newLength
	for(this->size; newLength > this->size; this->size *= 2);
	this->data = realloc(this->data, this->typeSize * this->size);
	this->length = newLength;
}

void Array_print(const struct Array* this, void (*print)(void*)) {
	for(size_t i = 0; i < this->length; i++) {
		printf("[%lu]: ", i);
		print((void*)((char*)this->data + (i * this->typeSize)));
		printf("\n");
	}
}