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

void Array_access(struct Array* this, size_t index, void* into) {
	copyElement(into,
		(void*)((char*)this->data + (index * this->typeSize)),
		this->typeSize);
}

void Array_assign(struct Array* this, size_t index, void* from) {
	copyElement((void*)((char*)this->data + (index * this->typeSize)),
		from,
		this->typeSize);
}

void Array_delete(struct Array* this, size_t index) {
	this->length--;
	for(index; index < this->length; index++) {
		void* nextElement = malloc(this->typeSize);
		Array_access(this, index + 1, nextElement);
		Array_assign(this, index, nextElement);
		free(nextElement);
	}
}

size_t Array_getSize(struct Array* this) {
	return this->size;
}

size_t Array_getLength(struct Array* this) {
	return this->length;
}	

void Array_pop(struct Array* this, void* into) {
	Array_access(this, this->length - 1, into);
	this->length--;
}

void Array_push(struct Array* this, void* from) {
	if(this->length == this->size) Array_resize(this, this->length + 1);
	else this->length++;
	Array_assign(this, this->length - 1, from);
}

void Array_resize(struct Array* this, size_t newLength) {
	for(this->size; newLength > this->size; this->size *= 2);
	this->data = realloc(this->data, this->typeSize * this->size);
	this->length = newLength;
}

void Array_print(struct Array* this, void (*print)(void*)) {
	for(size_t i = 0; i < this->length; i++) {
		printf("[%lu]: ", i);
		print((void*)((char*)this->data + (i * this->typeSize)));
		printf("\n");
	}
}

void copyElement(void* into, void* from, size_t typeSize) {
	for(size_t i = 0; i < typeSize; i++){
		*((char*)into + i) = *((char*)from + i);
	}
}

void print_int(void* num) {
	printf("%d", *((int*)num));
}

void print_double(void* num) {
	printf("%lf", *((double*)num));
}