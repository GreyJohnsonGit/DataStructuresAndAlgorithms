#include "LinkedList.h"
#include "Utility.h"
#include <stdio.h>

int TEST_LinkedList()
{
	struct LinkedList* list = LinkedList_init(sizeof(int));

	printf("\n\nInitialize LinkedList:\n");
	LinkedList_print(list, printInt);

	printf("\n\nAppend and Prepend:\n");
	for(size_t i = 0; i < 10; i++) {
		int num = (int)i;
		(i % 2) ? LinkedList_prepend(list, &num) : LinkedList_append(list, &num);
	}
	LinkedList_print(list, printInt);

	printf("\n\nAccess and Order:\n");
	struct LinkedListNode* current = LinkedList_head(list); 
	for(size_t i = 0; i < 10; i++) {
		int num = (int)i * 10;
		copy(LinkedListNode_access(current), &num, list->typeSize);
		current = LinkedListNode_forward(current, 1);
	}
	LinkedList_print(list, printInt);

	printf("\n\nAppend Node and Prepend Node:\n");
	for(size_t i = 10; i < 15; i++) {
		int num = (int) i * 10;
		int negNum = 90 - num;
		LinkedListNode_prepend(LinkedList_head(list), &negNum);
		LinkedListNode_append(LinkedList_tail(list), &num);
	}
	LinkedList_print(list, printInt);

	printf("\n\nDelete 5 in the Middle:\n");
	for(size_t i = 10; i < 15; i++) {
		LinkedListNode_delete(LinkedListNode_forward(LinkedList_head(list), 5));
	}
	LinkedList_print(list, printInt);

	LinkedList_free(list);

	return 0;
}
