#include "array.h"
#include <stdio.h>

int main()
{
	struct Array array1;
	Array_init(&array1, 10);

	size_t size, length;
	Array_getSize(&array1, &size);
	Array_getLength(&array1, &length);
	printf("Size: %zu\tLength: %zu\n", size, length);

	Array_free(&array1);
	return 0;
}
