// src/stack.c
#include "stack.h"

#include <stdlib.h>

void init(struct Stack* stack) { stack->top = NULL; }

int push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!newNode) {
        return FAIL;
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    return SUCCESS;
}

int pop(struct Stack* stack, int* data) {
    if (stack->top == NULL) {
        return FAIL;
    }

    struct StackNode* temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);

    return SUCCESS;
}

void destroy(struct Stack* stack) {
    while (stack->top != NULL) {
        struct StackNode* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}
