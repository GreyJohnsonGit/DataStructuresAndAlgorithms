#include <stdio.h>
#include "Stack.h"
#include "Utility.h"

int main() {
    struct Stack* stack = Stack_init(sizeof(size_t));

    printf("\n\nPushing Up Stack:\n");
    for (size_t i = 0; i < 10; i++) {
        Stack_push(stack, &i);
    }
    Stack_print(stack, printInt);

    printf("\n\nPeak and Pop:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("Peak n' Pop: %lu\n", *(size_t*)Stack_peak(stack));
        Stack_pop(stack);
    }
    Stack_print(stack, printInt);

    Stack_free(stack);

    return 0;
}