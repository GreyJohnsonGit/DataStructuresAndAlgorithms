#include "LinkedList.h"
#include "Utility.h"

int main()
{
	struct LinkedList list;
	
	LinkedList_init(&list, 5, sizeof(int));

	LinkedList_print(&list, printInt);

	LinkedList_free(&list);

	return 0;
}
