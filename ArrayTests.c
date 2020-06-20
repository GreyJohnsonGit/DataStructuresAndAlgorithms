#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Utility.h"

// Testing for Array functions

int main()
{
	struct Array* array = Array_init(10, sizeof(double));

	printf("\n\nInitialize array:\n");
	for (int i = 0; i < 10; i++)
	{
		double num = 3.14 * i;
		copy(Array_access(array, i), &num, sizeof(double));	
	}
	Array_print(array, printDouble);

	printf("\n\nAccess, Peak, Pop:\n");
	for (int i = 9; i >= 0; i--)
	{
		printf("Access: %lf ", *(double*)Array_access(array, i));
		printf("Peak: %lf \n", *(double*)Array_peak(array));
		Array_pop(array);
	}
	Array_print(array, printDouble);

	printf("\n\nPush up above size:\n");
	for (int i = 0; i < 20; i++)
	{
		double num = 2.0 * i;
		Array_push(array, (void*)&num);
		printf("Push: %lf \n", num);
	}
	Array_print(array, printDouble);

	printf("\n\nDelete [3]:\n");
	Array_delete(array, 3);
	Array_print(array, printDouble);

	printf("\n\nInsert 10 at [3]:\n");
	double num = 10.0;
	Array_insert(array, 3, &num);
	Array_print(array, printDouble);

	printf("\n\nCheck Length:\n%lu\n", Array_getLength(array));

	printf("\n\nResize to 1:\n");
	Array_resize(array, 1);
	Array_print(array, printDouble);

	Array_free(array);
	return 0;
}
