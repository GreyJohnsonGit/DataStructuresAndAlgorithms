#include <Array.h>
#include <Utility.h>

#include <stdio.h>
#include <stdlib.h>

int TEST_Array()
{
	struct Array* array = Array_create(10, sizeof(double));

	printf("\n\nInitialize array:\n");
	for (int i = 0; i < 10; i++)
	{
		double num = 3.14 * i;
		copy(Array_access(array, i), &num, sizeof(double));	
	}
	Array_print(array, printDouble);

	printf("\n\nAccess and Delete:\n");
	for (int i = 9; i >= 0; i--)
	{
		printf("Access: %lf \n", *(double*)Array_access(array, i));
		Array_delete(array, Array_getLength(array) - 1);
	}
	Array_print(array, printDouble);

	printf("\n\nInsert above size:\n");
	for (int i = 0; i < 20; i++)
	{
		double num = 2.0 * i;
		Array_insert(array, Array_getLength(array), (void*)&num);
		printf("Push: %lf \n", num);
	}
	Array_print(array, printDouble);

	printf("\n\nCheck Length:\n%lu\n", Array_getLength(array));

	printf("\n\nResize to 1:\n");
	Array_resize(array, 1);
	Array_print(array, printDouble);

	Array_destroy(array);
	return 0;
}
