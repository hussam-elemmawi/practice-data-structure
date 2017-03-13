//
// Created by hussamelemmawi on 23/01/17.
//

#include "tests.h"
#include <assert.h>

int passed_test = 0;

/**
 * Function to run all tests at once
 */
void run_all_tests() {
  test_size();
  ++passed_test;

  test_value_at();
  ++passed_test;

  test_is_empty();
  ++passed_test;

  test_push_back();
  ++passed_test;

  test_pop_front();
  ++passed_test;

  test_pop_back();
  ++passed_test;

  test_front();
  ++passed_test;

  test_back();
  ++passed_test;

  test_insert();
  ++passed_test;

  test_erase();
  ++passed_test;

  test_value_from_back();
  ++passed_test;

  test_remove();
  ++passed_test;

  test_reverse();
  ++passed_test;

  print_final_result();
}

void test_size() {
  int size = 0;

  linked_list *ll = ll_create_new();
  size = ll_size(ll);
  assert(size == 0);

  ll_push_front(ll, 5);
  size = ll_size(ll);
  assert(size == 1);

  ll_destroy(ll);
  print_passed("test_size");
}

void test_value_at() {
  linked_list *ll = ll_create_new();

  ll_push_front(ll, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_push_front(ll, 10);
  assert(ll_value_at(ll, 0) == 10);
  assert(ll_value_at(ll, 1) == 5);

  ll_destroy(ll);
  print_passed("test_value_at");
}

void test_is_empty() {
  linked_list *ll = ll_create_new();

  assert(ll_is_empty(ll) == 1);

  ll_push_front(ll, 5);
  assert(ll_is_empty(ll) == 0);

  ll_destroy(ll);
  print_passed("test_is_empty");
}

void test_push_back() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_push_back(ll, 10);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);

  ll_push_back(ll, 20);
  assert(ll_value_at(ll, 2) == 20);

  ll_destroy(ll);
  print_passed("test_push_back");
}

void test_pop_front() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 20);

  assert(ll_pop_front(ll) == 5);
  assert(ll_pop_front(ll) == 10);

  ll_destroy(ll);
  print_passed("test_pop_front");
}

void test_pop_back() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 20);

  assert(ll_pop_back(ll) == 20);
  assert(ll_pop_back(ll) == 10);

  ll_destroy(ll);
  print_passed("test_pop_back");
}

void test_front() {
  linked_list *ll = ll_create_new();

  ll_push_front(ll, 5);
  assert(ll_front(ll) == 5);

  ll_push_back(ll, 10);
  assert(ll_front(ll) == 5);

  ll_push_front(ll, 1);
  assert(ll_front(ll) == 1);

  ll_destroy(ll);
  print_passed("test_front");
}

void test_back() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  assert(ll_back(ll) == 5);

  ll_push_front(ll, 10);
  assert(ll_back(ll) == 5);

  ll_push_back(ll, 1);
  assert(ll_back(ll) == 1);

  ll_destroy(ll);
  print_passed("test_back");
}

void test_insert() {
  linked_list *ll = ll_create_new();

  ll_insert(ll, 0, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_insert(ll, 1, 10);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);

  ll_insert(ll, 2, 15);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);
  assert(ll_value_at(ll, 2) == 15);

  ll_insert(ll, 1, 7);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 7);
  assert(ll_value_at(ll, 3) == 15);

  ll_destroy(ll);
  print_passed("test_insert");
}

void test_erase() {
  linked_list *ll = ll_create_new();

  ll_push_front(ll, 5);
  ll_push_front(ll, 10);
  assert(ll_size(ll) == 2);

  ll_erase(ll, 1);
  assert(ll_size(ll) == 1);

  ll_erase(ll, 0);
  assert(ll_size(ll) == 0);

  //
  ll_erase(ll, 1);
  // Nothing erased, still size == zero
  assert(ll_size(ll) == 0);

  ll_destroy(ll);
  print_passed("test_erase");
}

void test_value_from_back() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 15);
  ll_push_back(ll, 20);

  assert(ll_value_at_from_back(ll, 2) == 15);

  ll_destroy(ll);
  print_passed("test_value_from_back");
}

void test_remove() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 5);
  ll_push_back(ll, 20);

  ll_remove(ll, 5);
  assert(ll_size(ll) == 3);
  assert(ll_value_at(ll, 0) == 10);

  ll_destroy(ll);
  print_passed("test_remove");
}

void test_reverse() {
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 15);
  ll_push_back(ll, 20);

  ll_reverse(ll);

  ll_destroy(ll);
  print_passed("test_reverse");
}

void print_passed(char str[]) {
  printf("%s***** %s *****\n", ANSI_COLOR_BLUE, str);
}

print_final_result() {
  if (passed_test == tests_number)
    printf(" all %d tests passed", tests_number);
  else
    printf(" %d/%d tests passed", passed_test, tests_number);
}