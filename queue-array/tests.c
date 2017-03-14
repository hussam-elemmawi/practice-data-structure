//
// Created by hussamelemmawi on 01/02/17.
//

#include "tests.h"
#include "queue.c"
#include <assert.h>
#include <stdio.h>

int passed_tests = 0;

void run_all_tests() {

  test_enqueue();
  ++passed_tests;

  test_deque();
  ++passed_tests;

  test_is_empty();
  ++passed_tests;

  test_is_full();
  ++passed_tests;

  print_final_result();
}


void test_enqueue() {
  Queue *queue = queue_create(5);

  assert(queue_is_empty(queue) == 1);

  queue_enqueue(queue, 1);
  assert(queue_is_empty(queue) == 0);
  assert(queue->array[0] == 1);

  queue_enqueue(queue, 2);
  assert(queue_is_empty(queue) == 0);
  assert(queue->array[1] == 2);

  queue_destroy(queue);
  print_passed("test_enqueue");
}

void test_deque() {

  Queue *queue = queue_create(5);

  assert(queue_is_empty(queue) == 1);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_enqueue(queue, 5);
  queue_deque(queue);
  queue_enqueue(queue, 6);

  assert(queue_is_empty(queue) == 0);
  assert(queue_deque(queue) == 2);
  assert(queue_deque(queue) == 3);

  queue_destroy(queue);
  print_passed("test_deque");
}

void test_is_empty() {

  Queue *queue = queue_create(5);

  assert(queue_is_empty(queue) == 1);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_enqueue(queue, 5);

  assert(queue_is_empty(queue) == 0);

  queue_destroy(queue);
  print_passed("test_is_empty");
}

void test_is_full() {
  Queue *queue = queue_create(5);

  assert(queue_is_full(queue) == 0);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_enqueue(queue, 5);

  queue_deque(queue);
  queue_deque(queue);
  queue_deque(queue);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);

  assert(queue_is_full(queue) == 1);

//  queue_print(queue);

  queue_destroy(queue);
  print_passed("test_is_full");
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