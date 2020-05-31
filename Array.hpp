#ifndef ARRAY
#define ARRAY

#include <stdlib.h>
#include <exception>
#include <stdexcept>

template <class T> class Array {

	T* array;
	unsigned int size;
	unsigned int length;

public:

	Array();
	Array(unsigned int size);
	~Array();

	Array<T>& operator=(const Array& rhs);
	T& operator[](unsigned int index);

	unsigned int GetLength();
	unsigned int GetSize();

	void PushBack(const T& value);
	T PopBack();

	void Resize(unsigned int newSize);
};

template <class T> Array<T>::Array() : Array(0) {}

template <class T> Array<T>::Array(unsigned int size) : length(0), size(size), array(nullptr) {
	array = (T*)malloc(sizeof(T) * this->size);
}

template <class T> Array<T>::~Array() {
	free((void*)array);
	array = nullptr;
}

template <class T> Array<T>& Array<T>::operator=(const Array& rhs) {
	size = rhs.size;
	length = rhs.length;

	free(static_cast<void*>(array));
	array = (T*)malloc(sizeof(T) * size);
	if (array != nullptr) {
		for (unsigned int i = 0; i < size; i++) {
			*(array + i) = *(rhs.array + i);
		}
	}
	return *this;
}

template <class T> T& Array<T>::operator[](unsigned int index) {
	return *(array + index);
}

template <class T> unsigned int Array<T>::GetLength() {
	return length;
}

template <class T> unsigned int Array<T>::GetSize() {
	return size;
}


template <class T> void Array<T>::PushBack(const T& value) {

	if (size == 0) Resize(1);
	if (size == length) Resize(size * 2);
		
	*(array + length) = value;
	length++;
}

template <class T> T Array<T>::PopBack() {
	if (length == 0) throw std::out_of_range("PopBack on zero length array");

	length--;
	return *(array + length);
}


template <class T> void Array<T>::Resize(unsigned int newSize) {
	if (newSize == 0) throw std::invalid_argument("Cannot realloc with 0"); // TODO Assign array to nullptr and add logic to accout for it in other functions.
	T* temp = (T*)realloc((void*)(array), sizeof(T) * newSize);
	if (temp != nullptr) {
		array = temp;
		size = newSize;
	}
}

#endif