#include "array.h"
#include <stdio.h>

int main()
{
	struct Array array;
	Array_init(&array, 10);

	size_t size, length;
	Array_getSize(&array, &size);
	Array_getLength(&array, &length);
	printf("Size: %zu\tLength: %zu\n", size, length);
	
	int* assignValuePtr = malloc(sizeof(int));
	*assignValuePtr = 25;
	Array_assign(&array, 5, (void**)&assignValuePtr);
	printf("array1[5] = 25\n");

	int* accessValuePtr;
	Array_access(&array, 5,(void**)&accessValuePtr);
        printf("array1[5]: %d\n", *accessValuePtr);

	Array_free(&array);
	return 0;
}
