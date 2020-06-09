#include "array.h"

int Array_init(struct Array* this, size_t length) {
	this->size = 1;
	this->data = malloc(sizeof(void*) * this->size);
	return Array_resize(this, length);
}

int Array_free(struct Array* this) {
	if(this->data == NULL) return -1;
	free(this->data);
	this->data = NULL;
	return 0;
}

int Array_access(struct Array* this, size_t index, void** element) {
	if(this->data == NULL) return -1;
	if(index >= this->length) return -1;
	*element = *(this->data + index);
	return 0;
}

int Array_assign(struct Array* this, size_t index, void** element) {
	if(this->data == NULL) return -1;
	if(index >= this->length) return -1;
	*(this->data + index) = *element;
	*element = NULL;
	return 0;
}

int Array_delete(struct Array* this, size_t index) {
	if(this->data == NULL) return -1;
	if(index >= this->length) return -1;
	while(index + 1 < this->length) {
		*(this->data + index) = *(this->data + index + 1);
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
	if(this->length == this->size) Array_resize(this, this->size*2);
	*(this->data + this->length) = *element;
	*element = NULL;
	this->length++;
	return 0;
}

int Array_resize(struct Array* this, size_t newLength) {
	if(this->data == NULL) return -1;
	while(newLength > this->size) {
		this->size *= 2;
	}
	this->data = realloc(this->data, sizeof(void*) * this->size);
	this->length = newLength;
	return 0;
}
