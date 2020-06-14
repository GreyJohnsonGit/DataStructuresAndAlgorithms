#include "LinkedList.h"
#include "Utility.h"

int main()
{
	struct LinkedList* list = LinkedList_init(5, sizeof(int));

	LinkedList_print(list, printInt);

	for (size_t i = 0; i < list->length; i++){
		int num = i * 10;
		LinkedList_assign(list, i, &num); 
	}

	LinkedList_print(list, printInt);

	LinkedList_free(list);

	return 0;
}
