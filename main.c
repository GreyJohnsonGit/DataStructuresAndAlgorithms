#include "array.h"
#include <stdio.h>

int main()
{
	struct Array array;
	Array_init(&array, 10, sizeof(double));

	for (size_t i = 0; i < 10; i++)
	{
		double* num = malloc(sizeof(double));
		*num = 3.14 * i;
		Array_assign(&array, i, (void*)num);
		free(num);	
	}
	
	Array_print(&array, print_double);

	Array_free(&array);
	return 0;
}
