#ifndef ARRAY
#define ARRAY

#include <stdlib.h>

struct Array {
	void** data;
	size_t size;
	size_t length;
};

int	Array_init	(struct Array* this, size_t size);
int	Array_free	(struct Array* this);
int	Array_access	(struct Array* this, size_t index, void* element);
//int	Array_assign	(struct Array* this, size_t index, void* element);
//int	Array_delete	(struct Array* this, size_t index);
int	Array_getSize	(struct Array* this, size_t* size);
int	Array_getLength	(struct Array* this, size_t* length);
//int	Array_push	(struct Array* this, void* data);
//int	Array_pop	(struct Array* this, void* data);
//int	Array_resize	(struct Array* this, size_t newSize);

#endif
