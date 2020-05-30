#ifndef ARRAY
#define ARRAY

#define ARRAY_GROWTH_FACTOR 2

#include <stdlib.h>
#include <exception>

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
	int arraySize = sizeof(T) * this->size;
	array = static_cast<T*>(malloc(arraySize));
	if (array == nullptr && arraySize != 0) {
		throw std::bad_alloc();
	}
}

template <class T> Array<T>::~Array() {
	free(static_cast<void*>(array));
	array = nullptr;
}

template <class T> Array<T>& Array<T>::operator=(const Array& rhs) {
	size = rhs.size;
	length = rhs.length;

	free(static_cast<void*>(array));
	int arraySize = sizeof(T) * size;
	array = static_cast<T*>(malloc(arraySize));
	if (array == nullptr && arraySize != 0) {
		throw std::bad_alloc();
	}

	for (unsigned int i = 0; i < size; i++) {
		*(array + i) = *(rhs.array + i);
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
	if (size > length) {
		*(array + length) = value;
	}
	else if (size == 0) {
		Resize(1);
		*(array) = value;
	}
	else {
		Resize(size = size * ARRAY_GROWTH_FACTOR);
		*(array + length) = value;
	}
	length++;
}

template <class T> T Array<T>::PopBack() {
	T out = *(array + length - 1);
	if (length > size / ARRAY_GROWTH_FACTOR) {
		length--;
	}
	else {
		Resize(size = size / ARRAY_GROWTH_FACTOR);
		length--;
	}
	return out;
}


template <class T> void Array<T>::Resize(unsigned int newSize) {
	array = (T*)realloc(static_cast<void*>(array), newSize);
	if (array == nullptr && newSize != 0) {
		throw std::bad_alloc();
	}
}
#endif