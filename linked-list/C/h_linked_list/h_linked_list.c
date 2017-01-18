//
// Created by hussamelemmawi on 17/01/17.
//
// H_linked_list functions implementation

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "h_linked_list.h"

/**
 * Create new H_linked_list
 */
H_linked_list *h_ll_create_new() {

  H_linked_list *new_h_ll = malloc(sizeof(H_linked_list));
  check_address(new_h_ll);

  new_h_ll->head = 0;
  new_h_ll->size = 0;
  return new_h_ll;
}

/**
 * Check address for a pointer
 */
void check_address(void *p) {
  if (p == NULL) {
    printf("Unable allocate memory.\n");
    exit(EXIT_FAILURE);
  }
}


/**
 * Destroy H_linked_list
 */
void h_ll_destroy(H_linked_list *h_ll) {

  Node *current = h_ll->head;
  Node *next;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }

  free(h_ll);
}

/**
 * Returns the size of the H_linked_list
 */
int h_ll_size(H_linked_list *h_ll) {
  return h_ll->size;
}

/**
 * Returns true(1) if H_linked_list is empty
 */
int h_ll_is_empty(H_linked_list *h_ll) {
  return h_ll->head == 0 ? 1 : 0;
}

/**
 * Returns the value at specified index
 */
int h_ll_value_at(H_linked_list *h_ll, int index) {

  int counter = 0;
  Node *item = h_ll->head;

  while (counter < index && item) {
    counter++;
    item = item->next;
  }

  return item->data;
}

/**
 * Push an item to the front of the H_linked_list (right after the head)
 */
void h_ll_push_front(H_linked_list *h_ll, int item) {
  Node *new_node = malloc(sizeof(Node));
  new_node->next = h_ll->head;
  new_node->data = item;

  h_ll->head = new_node;
  h_ll->size++;
}

/**
 * Prints the H_linked_list
 */
void h_ll_print(H_linked_list *h_ll) {

  Node *move = h_ll->head;

  while (move) {
    printf(" %d", move->data);
    move = move->next;
  }
}

/**
 * Push an item to the back of the H_linked_list
 */
void h_ll_push_back(H_linked_list *h_ll, int item) {

  Node *new_node = malloc(sizeof(Node));
  new_node->next = 0;
  new_node->data = item;

  if (h_ll->size == 0) {
    h_ll->head = new_node;
    new_node->data = item;
  } else {
    Node *current = h_ll->head;
    int size = h_ll->size;
    int counter = 1;

    while (counter < size) {
      counter++;
      current = current->next;
    }

    current->next = new_node;
    new_node->data = item;

  }

  h_ll->size++;
}

//////////////// tests ////////////////

/**
 * Function to run all tests at once
 */
void run_all_tests() {
  test_size();
  test_value_at();
  test_is_empty();
  test_push_back();
}

void test_size() {
  printf("***** test_size *****\n");
  int size = 0;

  H_linked_list *h_ll = h_ll_create_new();
  size = h_ll_size(h_ll);
  assert(size == 0);

  h_ll_print(h_ll);

  h_ll_push_front(h_ll, 5);
  size = h_ll_size(h_ll);
  assert(size == 1);

  h_ll_print(h_ll);

  h_ll_destroy(h_ll);
  printf("\n");
}

void test_value_at() {
  printf("***** test_value_at *****\n");

  H_linked_list *h_ll = h_ll_create_new();

  h_ll_print(h_ll);

  h_ll_push_front(h_ll, 5);
  assert(h_ll_value_at(h_ll, 0) == 5);

  h_ll_push_front(h_ll, 10);
  assert(h_ll_value_at(h_ll, 0) == 10);
  assert(h_ll_value_at(h_ll, 1) == 5);

  h_ll_print(h_ll);

  h_ll_destroy(h_ll);
  printf("\n");
}

void test_is_empty() {
  printf("***** test_is_empty *****\n");

  H_linked_list *h_ll = h_ll_create_new();

  assert(h_ll_is_empty(h_ll) == 1);

  h_ll_push_front(h_ll, 5);
  assert(h_ll_is_empty(h_ll) == 0);

  h_ll_destroy(h_ll);
  printf("\n");
}

void test_push_back() {
  printf("***** test_push_back *****\n");

  H_linked_list *h_ll = h_ll_create_new();

  h_ll_push_back(h_ll, 5);
  assert(h_ll_value_at(h_ll, 0) == 5);

  h_ll_push_back(h_ll, 10);
  assert(h_ll_value_at(h_ll, 0) == 5);
  assert(h_ll_value_at(h_ll, 1) == 10);

  h_ll_push_back(h_ll, 20);
  assert(h_ll_value_at(h_ll, 2) == 20);

  h_ll_print(h_ll);

  h_ll_destroy(h_ll);
  printf("\n");
}

