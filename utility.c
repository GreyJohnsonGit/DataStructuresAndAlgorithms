#include "utility.h"

void copyElement(void* into, const void* from, size_t typeSize) {
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