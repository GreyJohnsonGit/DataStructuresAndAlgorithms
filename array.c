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

void* Array_access(struct Array* this, size_t index) {
	char* out = malloc(this->typeSize);
	for(size_t i = 0; i < this->typeSize; i++){
		*(out + i) = *((char*)this->data + (index * this->typeSize) + i);
	}
	return (void*)out;
}

void Array_assign(struct Array* this, size_t index, void* element) {
	for(size_t i = 0; i < this->typeSize; i++){
		*((char*)this->data + (index * this->typeSize) + i) = *((char*)element + i);
	}
}
/*
int Array_delete(struct Array* this, size_t index) {
	while(index + 1 < this->length) {
		for(int i = 0; i < this->typeSize; i++){
			*((char*)this->data + index + i) = *((char*)this->data + (index + 1) + i);
		}
		index++;
	}
	this->length--;
	return 0;
}

int Array_getSize(struct Array* this, size_t* size) {
	*size = this->size;
	return 0;
}

int Array_getLength(struct Array* this, size_t* length) {
	*length = this->length;
	return 0;
}

int Array_pop(struct Array* this, void** element) {
	
	if(this->data == NULL) return -1;
	
	*element = *(this->data + this->length - 1);
	this->length--;
	return 0;
}

int Array_push(struct Array* this, void** element) {
	
	if(this->data == NULL) return -1;
	
	if(this->length == this->size) Array_resize(this, this->length + 1);
	else this->length++;
	*(this->data + (this->length - 1) * sizeof(void*)) = *element;
	*element = NULL;
	return 0;
}
*/
void Array_resize(struct Array* this, size_t newLength) {
	while(newLength > this->size) {
		this->size *= 2;
	}
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

void print_int(void* num) {
	printf("%d", *((int*)num));
}

void print_double(void* num) {
	printf("%lf", *((double*)num));
}