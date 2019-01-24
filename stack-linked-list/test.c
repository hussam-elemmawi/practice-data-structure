//
// Created by hussamelemmawi on 30/01/17.
//

#include "test.h"
#include "stack.c"
#include <assert.h>
#include <stdio.h>

int passed_tests = 0;

void run_all_tests() {

  test_push();
  ++passed_tests;

  test_pop();
  ++passed_tests;

  test_top();
  ++passed_tests;

  test_is_empty();
  ++passed_tests;

  print_final_result();
}

void test_push() {
  Stack *stack = stack_create();

  stack_push(stack, 0);
  assert(stack->head->data == 0);

  stack_push(stack, 1);
  assert(stack->head->data == 1);

  stack_destroy(stack);
  print_passed("test_push");
}

void test_pop() {
  Stack *stack = stack_create();

  stack_push(stack, 0);
  stack_push(stack, 1);
  stack_push(stack, 2);
  assert(stack_pop(stack) == 2);
  assert(stack_pop(stack) == 1);
  assert(stack_pop(stack) == 0);

  assert(stack_is_empty(stack) == 1);

  stack_destroy(stack);
  print_passed("test_pop");
}

void test_top() {
  Stack *stack = stack_create();

  stack_push(stack, 0);
  stack_push(stack, 1);
  stack_push(stack, 2);
  assert(stack_top(stack) == 2);
  stack_pop(stack);
  assert(stack_top(stack) == 1);
  stack_pop(stack);
  assert(stack_top(stack) == 0);

  assert(stack_is_empty(stack) == 0);

  stack_destroy(stack);
  print_passed("test_top");
}

void test_is_empty() {
  Stack *stack = stack_create();

  assert(stack_is_empty(stack) == 1);

  stack_push(stack, 5);
  assert(stack_is_empty(stack) == 0);

  stack_destroy(stack);
  print_passed("test_is_empty");
}

void print_passed(char str[]) {
  printf("%s***** %s *****\n", ANSI_COLOR_BLUE, str);
}

print_final_result() {

  if (passed_tests == tests_number)
    printf(" all %d tests passed", tests_number);
  else
    printf(" %d/%d tests passed", passed_tests, tests_number);
}