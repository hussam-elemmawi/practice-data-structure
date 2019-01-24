//
// Created by hussamelemmawi on 23/01/17.
//

#include "tests.h"

int passed_tests = 0;

/**
 * Function to run all tests at once
 */
void run_all_tests() {
  test_size();
  ++passed_tests;

  test_value_at();
  ++passed_tests;

  test_is_empty();
  ++passed_tests;

  test_push_back();
  ++passed_tests;

  test_pop_front();
  ++passed_tests;

  test_pop_back();
  ++passed_tests;

  test_front();
  ++passed_tests;

  test_back();
  ++passed_tests;

  test_insert();
  ++passed_tests;

  test_erase();
  ++passed_tests;

  test_value_from_back();
  ++passed_tests;

  test_remove();
  ++passed_tests;

  test_reverse();
  ++passed_tests;

  print_final_result();
}

void test_size() {
  int size = 0;

  H_linked_list *h_ll = h_ll_create_new();
  size = h_ll_size(h_ll);
  assert(size == 0);

  h_ll_push_front(h_ll, 5);
  size = h_ll_size(h_ll);
  assert(size == 1);

  h_ll_destroy(h_ll);
  print_passed("test_size");
}

void test_value_at() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_front(h_ll, 5);
  assert(h_ll_value_at(h_ll, 0) == 5);

  h_ll_push_front(h_ll, 10);
  assert(h_ll_value_at(h_ll, 0) == 10);
  assert(h_ll_value_at(h_ll, 1) == 5);

  h_ll_destroy(h_ll);
  print_passed("test_value_at");
}

void test_is_empty() {
  H_linked_list *h_ll = h_ll_create_new();

  assert(h_ll_is_empty(h_ll) == 1);

  h_ll_push_front(h_ll, 5);
  assert(h_ll_is_empty(h_ll) == 0);

  h_ll_destroy(h_ll);
  print_passed("test_is_empty");
}

void test_push_back() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  assert(h_ll_value_at(h_ll, 0) == 5);

  h_ll_push_back(h_ll, 10);
  assert(h_ll_value_at(h_ll, 0) == 5);
  assert(h_ll_value_at(h_ll, 1) == 10);

  h_ll_push_back(h_ll, 20);
  assert(h_ll_value_at(h_ll, 2) == 20);

  h_ll_destroy(h_ll);
  print_passed("test_push_back");
}

void test_pop_front() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 10);
  h_ll_push_back(h_ll, 20);

  assert(h_ll_pop_front(h_ll) == 5);
  assert(h_ll_pop_front(h_ll) == 10);

  h_ll_destroy(h_ll);
  print_passed("test_pop_front");
}

void test_pop_back() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 10);
  h_ll_push_back(h_ll, 20);

  assert(h_ll_pop_back(h_ll) == 20);
  assert(h_ll_pop_back(h_ll) == 10);

  h_ll_destroy(h_ll);
  print_passed("test_pop_back");
}

void test_front() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_front(h_ll, 5);
  assert(h_ll_front(h_ll) == 5);

  h_ll_push_back(h_ll, 10);
  assert(h_ll_front(h_ll) == 5);

  h_ll_push_front(h_ll, 1);
  assert(h_ll_front(h_ll) == 1);

  h_ll_destroy(h_ll);
  print_passed("test_front");
}

void test_back() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  assert(h_ll_back(h_ll) == 5);

  h_ll_push_front(h_ll, 10);
  assert(h_ll_back(h_ll) == 5);

  h_ll_push_back(h_ll, 1);
  assert(h_ll_back(h_ll) == 1);

  h_ll_destroy(h_ll);
  print_passed("test_back");
}

void test_insert() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_insert(h_ll, 0, 5);
  assert(h_ll_value_at(h_ll, 0) == 5);

  h_ll_insert(h_ll, 1, 10);
  assert(h_ll_value_at(h_ll, 0) == 5);
  assert(h_ll_value_at(h_ll, 1) == 10);

  h_ll_insert(h_ll, 2, 15);
  assert(h_ll_value_at(h_ll, 0) == 5);
  assert(h_ll_value_at(h_ll, 1) == 10);
  assert(h_ll_value_at(h_ll, 2) == 15);

  h_ll_insert(h_ll, 1, 7);
  assert(h_ll_value_at(h_ll, 0) == 5);
  assert(h_ll_value_at(h_ll, 2) == 7);
  assert(h_ll_value_at(h_ll, 3) == 15);

  h_ll_destroy(h_ll);
  print_passed("test_insert");
}

void test_erase() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_front(h_ll, 5);
  h_ll_push_front(h_ll, 10);
  assert(h_ll->size == 2);

  h_ll_erase(h_ll, 1);
  assert(h_ll->size == 1);

  h_ll_erase(h_ll, 0);
  assert(h_ll->size == 0);

  h_ll_erase(h_ll, 1);
  h_ll_destroy(h_ll);
  print_passed("test_erase");
}

void test_value_from_back() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 10);
  h_ll_push_back(h_ll, 15);
  h_ll_push_back(h_ll, 20);

  assert(h_ll_value_at_from_back(h_ll, 2) == 15);

  h_ll_destroy(h_ll);
  print_passed("test_value_from_back");
}

void test_remove() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 10);
  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 20);

  h_ll_remove(h_ll, 5);
  assert(h_ll->size == 3);
  assert(h_ll_value_at(h_ll, 0) == 10);

  h_ll_destroy(h_ll);
  print_passed("test_remove");
}

void test_reverse() {
  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  h_ll_push_back(h_ll, 10);
  h_ll_push_back(h_ll, 15);
  h_ll_push_back(h_ll, 20);

  h_ll_reverse(h_ll);

  h_ll_destroy(h_ll);
  print_passed("test_reverse");
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