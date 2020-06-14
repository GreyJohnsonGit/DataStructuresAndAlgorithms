#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Utility.h"

// Testing for Array functions

int main()
{
	struct Array* array = Array_init(10, sizeof(double));

	for (int i = 0; i < 10; i++)
	{
		double num = 3.14 * i;
		Array_assign(array, i, (void*)&num);	
	}

	Array_print(array, printDouble);

	for (int i = 9; i >= 0; i--)
	{
		printf("Access: %lf ", *(double*)Array_access(array, i));
		printf("Peak: %lf \n", *(double*)Array_peak(array));
		Array_pop(array);
	}

	Array_print(array, printDouble);

	for (int i = 0; i < 10; i++)
	{
		double num = 2.0 * i;
		Array_push(array, (void*)&num);
		printf("Push: %lf ", num);
		printf("Access: %lf \n", *(double*)Array_access(array, i));
	}

	Array_print(array, printDouble);

	Array_free(array);
	return 0;
}
