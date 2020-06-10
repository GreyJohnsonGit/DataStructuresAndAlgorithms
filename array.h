#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>

struct Array {
	void* data;
	size_t typeSize;
	size_t size;
	size_t length;
};

void	Array_init		(struct Array* this, size_t length, size_t typeSize);
void	Array_free		(struct Array* this);
void	Array_access	(struct Array* this, size_t index, void* into);
void	Array_assign	(struct Array* this, size_t index, void* from);
void	Array_delete	(struct Array* this, size_t index);
size_t	Array_getSize	(struct Array* this);
size_t	Array_getLength	(struct Array* this);
void	Array_pop		(struct Array* this, void* into);
void	Array_push		(struct Array* this, void* from);
void	Array_resize	(struct Array* this, size_t newLength);
void	Array_print	(struct Array* this, void (*print)(void*));

void copyElement(void* into, void* from, size_t typeSize);

void	print_int(void* num);
void	print_double(void* num);

#endif
