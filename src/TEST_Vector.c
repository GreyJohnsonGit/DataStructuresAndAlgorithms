#include <DSAA_Vector.h>
#include <Utility.h>
#include <Vector.h>
#include <stdio.h>
#include <stdlib.h>

int TEST_Vector()
{
	struct Vector* vec = DSAA_Vector(10, sizeof(double));

	printf("\n\nInitialize array:\n");
	for (int i = 0; i < 10; i++)
	{
		double num = 3.14 * i;
		copy(vec->Access(vec, i), &num, sizeof(double));	
	}
	vec->Foreach(vec, printDouble, NULL);

	printf("\n\nAccess and Delete:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Access: %lf \n", *(double*)vec->Access(vec, 0));
		vec->Delete(vec, 0);
	}
	vec->Foreach(vec, printDouble, NULL);

	printf("\n\nInsert above size:\n");
	for (int i = 0; i < 20; i++)
	{
		double num = 2.0 * i;
		vec->Insert(vec, vec->GetLength(vec), (void*)&num);
		printf("Insert: %lf \n", num);
	}
	vec->Foreach(vec, printDouble, NULL);

	printf("\n\nCheck Length:\n%lu\n", vec->GetLength(vec));

	printf("\n\nResize to 1:\n");
	vec->Resize(vec, 1);
	vec->Foreach(vec, printDouble, NULL);

	vec->Destroy(vec);
	return 0;
}
