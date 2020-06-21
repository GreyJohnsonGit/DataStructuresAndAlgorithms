#ifndef UTILITY_H_
#define UTILITY_H_

#include <stddef.h>

void copy(void* into, const void* from, size_t typeSize);
void printInt(void* num);
void printDouble(void* num);

#endif