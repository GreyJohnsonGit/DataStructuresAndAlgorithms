#include <Utility.h>

#include <stdio.h>

void copy(void* into, const void* from, size_t typeSize) {
	for (size_t i = 0; i < typeSize; i++){
		*((char*)into + i) = *((char*)from + i);
	}
}

void printInt(const void* num, void* closure) {
	printf("%d, ", *((int*)num));
}

void printDouble(const void* num, void* closure) {
	printf("%lf, ", *((double*)num));
}