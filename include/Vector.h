#include <stddef.h>

#ifndef VECTOR_H
#define VECTOR_H

struct Vector
{
    void    (*Destroy)      (struct Vector* this);
    void*   (*Access)       (struct Vector* this, size_t index);
    size_t  (*GetLength)    (struct Vector* this);
    void    (*Foreach)      (struct Vector* this, void(*action)(void* value, void* closure), void* closure);
    void    (*Insert)       (struct Vector* this, size_t index, void* source);
    void    (*Delete)       (struct Vector* this, size_t index);
    void    (*Resize)       (struct Vector* this, size_t length);

    void*   _inner;
};

#endif