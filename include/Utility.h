#include <stddef.h>

#ifndef UTILITY_H_
#define UTILITY_H_

void copy(void* into, const void* from, size_t typeSize);
void printInt(const void* num, void* closure);
void printDouble(const void* num, void* closure);

#endif