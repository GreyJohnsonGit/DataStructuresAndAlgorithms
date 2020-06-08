#include "array.h"

int Array_init(struct Array* this, size_t size) {
	if(size == 0) {
		this->data = NULL;
        	this->size = 0;
	}
	else {
		this->data = malloc(sizeof(void*) * size);
        	this->size = size;
	}
	this->length = 0;
	return 0;
}

int Array_free(struct Array* this) {
	if(this->data == NULL) return -1;
	free(this->data);
	this->data = NULL;
	return 0;
}

int Array_access(struct Array* this, size_t index, void* element) {
	if(this->data == NULL) return -1;
	if(index > this->length) return -1;
	element = *(this->data + index);
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

int Array_resize(struct Array* this, size_t newSize) {
	if(this->data == NULL) return -1;
	if(newSize == 0) return -1;
	this->data = realloc(this->data, newSize);
	this->size = newSize;
	if(this->length > newSize) this->length = newSize;
	return 0;
}
