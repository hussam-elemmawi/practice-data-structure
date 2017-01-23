//
// Created by hussamelemmawi on 23/01/17.
//

#include "tests.h"

/**
 * Function to run all tests at once
 */
void run_all_tests() {
  test_size();
  test_value_at();
  test_is_empty();
  test_push_back();
  test_pop_front();
  test_pop_back();
  test_front();
  test_back();
  test_insert();
  test_erase();
  test_value_from_back();
  test_remove();
  test_reverse();
}

void test_size() {
  printf("***** test_size *****\n");
  int size = 0;

  linked_list *ll = ll_create_new();
  size = ll_size(ll);
  assert(size == 0);

  ll_print(ll);

  ll_push_front(ll, 5);
  size = ll_size(ll);
  assert(size == 1);

  ll_print(ll);

  ll_destroy(ll);
  printf("\n");
}

void test_value_at() {
  printf("***** test_value_at *****\n");

  linked_list *ll = ll_create_new();

  ll_print(ll);

  ll_push_front(ll, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_push_front(ll, 10);
  assert(ll_value_at(ll, 0) == 10);
  assert(ll_value_at(ll, 1) == 5);

  ll_print(ll);

  ll_destroy(ll);
  printf("\n");
}

void test_is_empty() {
  printf("***** test_is_empty *****\n");

  linked_list *ll = ll_create_new();

  assert(ll_is_empty(ll) == 1);

  ll_push_front(ll, 5);
  assert(ll_is_empty(ll) == 0);

  ll_destroy(ll);
  printf("\n");
}

void test_push_back() {
  printf("***** test_push_back *****\n");

  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_push_back(ll, 10);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);

  ll_push_back(ll, 20);
  assert(ll_value_at(ll, 2) == 20);

  ll_print(ll);

  ll_destroy(ll);
  printf("\n");
}

void test_pop_front() {
  printf("***** test_pop_front *****\n");

  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 20);

  assert(ll_pop_front(ll) == 5);
  assert(ll_pop_front(ll) == 10);

  ll_print(ll);

  ll_destroy(ll);
  printf("\n");
}

void test_pop_back() {
  printf("***** test_pop_back *****\n");

  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 20);

  ll_print(ll);

  assert(ll_pop_back(ll) == 20);
  assert(ll_pop_back(ll) == 10);

  ll_print(ll);

  ll_destroy(ll);
  printf("\n");
}

void test_front() {
  printf("***** test_front *****\n");

  linked_list *ll = ll_create_new();

  ll_push_front(ll, 5);
  assert(ll_front(ll) == 5);

  ll_push_back(ll, 10);
  assert(ll_front(ll) == 5);

  ll_push_front(ll, 1);
  assert(ll_front(ll) == 1);

  ll_print(ll);
  ll_destroy(ll);
  printf("\n");
}

void test_back() {
  printf("***** test_back *****\n");

  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  assert(ll_back(ll) == 5);

  ll_push_front(ll, 10);
  assert(ll_back(ll) == 5);

  ll_push_back(ll, 1);
  assert(ll_back(ll) == 1);

  ll_print(ll);
  ll_destroy(ll);
  printf("\n");
}

void test_insert() {
  printf("***** test_insert *****\n");

  linked_list *ll = ll_create_new();

  ll_insert(ll, 0, 5);
  assert(ll_value_at(ll, 0) == 5);

  ll_print(ll);
  printf("\n");

  ll_insert(ll, 1, 10);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);

  ll_print(ll);
  printf("\n");

  ll_insert(ll, 2, 15);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 10);
  assert(ll_value_at(ll, 2) == 15);

  ll_print(ll);
  printf("\n");

  ll_insert(ll, 1, 7);
  assert(ll_value_at(ll, 0) == 5);
  assert(ll_value_at(ll, 1) == 7);
  assert(ll_value_at(ll, 3) == 15);

  ll_print(ll);
  ll_destroy(ll);
  printf("\n");
}

void test_erase() {
  printf("***** test_erase *****\n");
  linked_list *ll = ll_create_new();

  ll_push_front(ll, 5);
  ll_push_front(ll, 10);
  assert(ll_size(ll) == 2);
  ll_print(ll);
  printf("\n");

  ll_erase(ll, 1);
  assert(ll_size(ll) == 1);
  ll_print(ll);
  printf("\n");

  ll_erase(ll, 0);
  assert(ll_size(ll) == 0);
  ll_print(ll);

  ll_erase(ll, 1);
  ll_print(ll);
  ll_destroy(ll);
  printf("\n");
}

void test_value_from_back() {
  printf("***** test_value_from_back *****\n");
  linked_list *ll = ll_create_new();

  ll_print(ll);

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 15);
  ll_push_back(ll, 20);

  ll_print(ll);
  printf("\n");

  assert(ll_value_at_from_back(ll, 2) == 15);

  ll_print(ll);
  ll_destroy(ll);
  printf("\n");
}

void test_remove() {
  printf("***** test_remove *****\n");
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 5);
  ll_push_back(ll, 20);

  ll_remove(ll, 5);
  assert(ll_size(ll) == 3);
  assert(ll_value_at(ll, 0) == 10);

  ll_print(ll);
  printf("\n");

  ll_destroy(ll);
  printf("\n");
}

void test_reverse() {
  printf("***** test_reverse *****\n");
  linked_list *ll = ll_create_new();

  ll_push_back(ll, 5);
  ll_push_back(ll, 10);
  ll_push_back(ll, 15);
  ll_push_back(ll, 20);

  ll_print(ll);
  printf("\n");

  ll_reverse(ll);

  ll_print(ll);
  printf("\n");

  ll_destroy(ll);
  printf("\n");
}
