#include "linkedList.h"

int main()
{
	struct LinkedList list;
	
	LinkedList_init(&list, 5, sizeof(int));

	return 0;
}
