//
// Created by hussamelemmawi on 30/01/17.
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() {
  Stack *new_stack = malloc(sizeof(Stack));
  check_address(new_stack);
  new_stack->head = NULL;
  return new_stack;
}

void stack_destroy(Stack *stack) {
  if (!stack_is_empty(stack)) {
    Node *current = stack->head;
    do {
      stack->head = current->next;
      current = NULL;
      free(current);
      current = stack->head;
    } while (current);
  }
}

void stack_push(Stack *stack, int item) {
  Node *new_node = malloc(sizeof(Node));
  check_address(new_node);

  new_node->data = item;
  new_node->next = stack->head;
  stack->head = new_node;
}

int stack_pop(Stack *stack) {
  if (!stack_is_empty(stack)) {
    int ret_value = stack->head->data;
    stack->head = stack->head->next;
    return ret_value;
  }
}

int stack_top(Stack *stack) {
  if (!stack_is_empty(stack))
    return stack->head->data;
  else {
    printf("Stack is empty");
    return -1;
  }
}

int stack_is_empty(Stack *stack) {
  return stack->head == NULL;
}

void check_address(void *p) {
  if (p == NULL) {
    printf("Address not found");
    exit(EXIT_FAILURE);
  }
}

void stack_print(Stack *stack) {

  if (!stack_is_empty(stack)) {
    Node *current = stack->head;
    do {
      printf("%d \n", current->data);
      current = current->next;
    } while (current);
    printf("\n");
  }
}
