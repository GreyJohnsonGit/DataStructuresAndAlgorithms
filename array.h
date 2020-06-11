#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include "utility.h"

struct Array {
	void* data;
	size_t typeSize;
	size_t size;
	size_t length;
};

/*
*	Initialize $this with given type and length. Automatically adjusts size to fit
*	length.
*/
void	Array_init		(struct Array* this, size_t length, size_t typeSize);

/*
*	Free allocated memory.
*/
void	Array_free		(struct Array* this);

/*
*	Element at $index is byte copied from $this into $into.
*/
void	Array_access	(const struct Array* this, size_t index, void* into);

/*
*	$from is byte copied into the element at $index in $this.
*/
void	Array_assign	(struct Array* this, size_t index, const void* from);

/*
*	Deletes element at $index from $this. Elements are consolidated into
*	continuous array.
*/
void	Array_delete	(struct Array* this, size_t index);

/*
*	Returns the size of $this.
*/
size_t	Array_getSize	(const struct Array* this);

/*
*	Returns the length of $this.
*/
size_t	Array_getLength	(const struct Array* this);

/*
*	Pops final element from $this into $into. The popped element is deleted and
*	array length is shortened.
*/
void	Array_pop		(struct Array* this, void* into);

/*
*	$from is byte copied to the end of $this.
*/
void	Array_push		(struct Array* this, const void* from);

/*
*	Resize $this to length $newLength. Array size is automatically adjusted in
*	powers of 2.
*/
void	Array_resize	(struct Array* this, size_t newLength);

/*
*	$this is printed in format '[index]: print\n' where index is the element's
*	index and print is the output of the $print function.
*/
void	Array_print		(const struct Array* this, void (*print)(void*));

#endif
