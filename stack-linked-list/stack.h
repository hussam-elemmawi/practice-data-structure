//
// Created by hussamelemmawi on 30/01/17.
//

#ifndef STACK_LINKED_LIST_STACK_H
#define STACK_LINKED_LIST_STACK_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *head;
} Stack;

Stack *stack_create();

void stack_destroy(Stack *stack);

void stack_push(Stack *stack, int item);

int stack_pop(Stack *stack);

int stack_top(Stack *stack);

int stack_is_empty();

void check_address(void *p);

void stack_print(Stack *stack);

#endif //STACK_LINKED_LIST_STACK_H
