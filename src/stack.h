// src/stack.h

#ifndef STACK_H
#define STACK_H

#define SUCCESS 0
#define FAIL 1

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

void init(struct Stack* stack);
int push(struct Stack* stack, int data);
int pop(struct Stack* stack, int* data);
void destroy(struct Stack* stack);

#endif
