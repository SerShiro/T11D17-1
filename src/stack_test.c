#include "stack.h"

#include <stdio.h>

void test_push_pop() {
    struct Stack stack;
    init(&stack);

    for (int i = 0; i <= 5; ++i) {
        if (push(&stack, i) != SUCCESS) {
            destroy(&stack);
            printf("FAIL\n");
        }
    }
    printf("SUCCESS\n");

    for (int i = 5; i >= 0; --i) {
        int data;
        if (pop(&stack, &data) != SUCCESS || data != i) {
            destroy(&stack);
            printf("FAIL");
        }
    }

    destroy(&stack);
    printf("SUCCESS");
}

int main() {
    test_push_pop();
    return 0;
}
