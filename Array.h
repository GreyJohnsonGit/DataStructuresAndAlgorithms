#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

/*
*	Generic Array Struct
*/
struct Array {
	void* data;
	size_t typeSize;
	size_t size;
	size_t length;
};

/*
*	Return new Array with $length and $typeSize (And proper size).
*/
struct Array* Array_init(size_t length, size_t typeSize);

/*
*	Free allocated memory.
*/
void Array_free(struct Array* this);

/*
*	Return pointer to element at $index.
*/
void* Array_access(const struct Array* this, size_t index);

/*
*	Element $from is byte copied into the element at $index.
*/
void Array_assign(struct Array* this, size_t index, const void* from);

/*
*	Deletes element at $index. Elements are consolidated into continuous
*	array.
*/
void Array_delete(struct Array* this, size_t index);

/*
*	Element $from is byte copied into $index. Elements are shifted to
*	allow for the new element.
*/
void Array_insert(struct Array* this, size_t index, void* from);

/*
*	Returns the length of $this.
*/
size_t Array_getLength(const struct Array* this);

/*
*	Returns pointer to final element of $this.
*/
void* Array_peak(const struct Array* this);

/*
*	Removes final element from $this.
*/
void Array_pop(struct Array* this);

/*
*	$from is byte copied to the end of $this.
*/
void Array_push(struct Array* this, const void* from);

/*
*	Resize $this to length $newLength. Array size is automatically adjusted in
*	powers of 2.
*/
void Array_resize(struct Array* this, size_t newLength);

/*
*	$this is printed in format '[index]: print\n' where index is the element's
*	index and print is the output of the $print function.
*/
void Array_print(const struct Array* this, void (*print)(void*));

#endif
