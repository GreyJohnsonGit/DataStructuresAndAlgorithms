#ifndef UTILITY_H_
#define UTILITY_H_

#include <stddef.h>

/*
*   Bytewise Copy from $from into $into using type $typesize.
*/
void    copy        (void* into, const void* from, size_t typeSize);

/*
*   Print generic pointer content $num to console as int.
*/
void    printInt    (void* num);

/*
*   Print generic pointer content $num to console as double.
*/
void    printDouble (void* num);

#endif