#include "array.h"

// Testing for Array functions

int main()
{
	struct Array array;
	Array_init(&array, 10, sizeof(double));

	for (int i = 0; i < 10; i++)
	{
		double num = 3.14 * i;
		Array_assign(&array, i, (void*)&num);	
	}

	Array_print(&array, print_double);

	for (int i = 9; i >= 0; i--)
	{
		double num;
		Array_access(&array, i, (void*)&num);
		printf("Access: %lf ", num);
		num = 0;
		Array_pop(&array, (void*)&num);
		printf("Pop: %lf \n", num);
	}

	Array_print(&array, print_double);

	for (int i = 0; i < 10; i++)
	{
		double num = 2.0 * i;
		Array_push(&array, (void*)&num);
		printf("Push: %lf ", num);
		num = 0;
		Array_access(&array, i, (void*)&num);
		printf("Access: %lf \n", num);
	}

	Array_print(&array, print_double);

	Array_free(&array);
	return 0;
}
