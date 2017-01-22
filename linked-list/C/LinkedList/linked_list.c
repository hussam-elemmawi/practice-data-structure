//
// Created by hussamelemmawi on 17/01/17.
//
// linked_list functions implementation

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

/**
 * Create new linked_list
 */
linked_list *ll_create_new() {

  linked_list *new_ll = malloc(sizeof(linked_list));
  check_address(new_ll);

  new_ll->head = 0;
  return new_ll;
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
 * Destroy linked_list
 */
void ll_destroy(linked_list *ll) {

  Node *current = ll->head;
  Node *next;

  while (current) {
    next = current->next;
    current = NULL;
    free(current);
    current = next;
  }
  ll = NULL;
  free(ll);
}

/**
 * Returns the size of the linked_list
 */
int ll_size(linked_list *ll) {

  Node *current = ll->head;

  if (current == NULL) return 0;
  else {
    int counter = 0;
    while (current) {
      counter++;
      current = current->next;
    }
    return counter;
  }
}

/**
 * Returns true(1) if linked_list is empty
 */
int ll_is_empty(linked_list *ll) {
  return ll->head == 0 ? 1 : 0;
}

/**
 * Returns the value at specified index
 */
int ll_value_at(linked_list *ll, int index) {

  if (ll->head == NULL) return;
  else {
    int counter = 0;
    Node *item = ll->head;

    while (counter < index && item) {
      counter++;
      item = item->next;
    }

    return item->data;
  }
}

/**
 * Push an item to the front of the linked_list (right after the head)
 */
void ll_push_front(linked_list *ll, int item) {
  Node *new_node = malloc(sizeof(Node));
  new_node->next = ll->head;
  new_node->data = item;

  ll->head = new_node;
}

/**
 * Prints the linked_list
 */
void ll_print(linked_list *ll) {

  if (ll->head == NULL) {
    printf("Nothing to print\n");
    return;
  }

  Node *move = ll->head;
  while (move) {
    printf(" %d", move->data);
    move = move->next;
  }
}

/**
 * Push an item to the back of the linked_list
 */
void ll_push_back(linked_list *ll, int item) {

  Node *new_node = malloc(sizeof(struct node));
  new_node->next = 0;
  new_node->data = item;

  if (ll->head == 0) {
    ll->head = new_node;
  } else {
    Node *current = ll->head;
    while (current->next) {
      current = current->next;
    }

    current->next = new_node;
  }
}

/**
 * Pop an item from the front(start) of linked_list
 */
int ll_pop_front(linked_list *ll) {

  int value = ll->head->data;
  Node *nodeToPop = ll->head;
  ll->head = nodeToPop->next;

  nodeToPop = NULL;
  free(nodeToPop);
  return value;
}

/**
 * Pop an item from the back of linked_list
 */
int ll_pop_back(linked_list *ll) {

  if (ll->head == NULL) return;

  Node *current = ll->head;
  Node *previous = current;

  while (current->next) {
    previous = current;
    current = current->next;
  }

  int value = current->data;
  // The free() function causes the space pointed to by ptr to be deallocated
  // But not to be NULL
  previous->next = NULL;
  free(previous->next);
  return value;
}

/**
 * Return the value on the front(start) of linked_list
 */
int ll_front(linked_list *ll) {
  return ll_value_at(ll, 0);
}

/**
 * Return the value on the back(end) of linked_list
 */
int ll_back(linked_list *ll) {
  return ll_value_at(ll, ll_size(ll) - 1);
}

/**
 * Insert value at index
 */
void ll_insert(linked_list *ll, int index, int value) {

  int size = ll_size(ll);
  if (index > size || index < 0) return;
  if (index == 0 && size == 0) ll_push_front(ll, value);
  else if (index == size) ll_push_back(ll, value);
  else {

    Node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    // The allocation happens inside the linked list!
    // while initializing this new node the list linking breaks!
//    new_node->next = 0;

    int counter = 1;
    Node *previous_node = ll->head;
    Node *next_node = previous_node->next;

    while (counter < index) {
      counter++;
      previous_node = previous_node->next;
    }

    next_node = previous_node->next;
    previous_node->next = new_node;
    new_node->next = next_node;
  }
}

/**
 * Erase value at index
 */
void ll_erase(linked_list *ll, int index) {

  int size = ll_size(ll);
  if (size == 0 || index >= size) return;
  if (index == 0) {
    ll_pop_front(ll);
  } else if (index == size - 1) {
    ll_pop_back(ll);
  } else {

    int counter = 0;
    Node *previous_node = ll->head;
    Node *next_node = previous_node->next;
    Node *to_delete_node;

    while (counter < index) {
      counter++;
      previous_node = previous_node->next;
    }

    next_node = previous_node->next->next;
    to_delete_node = previous_node->next;
    previous_node->next = next_node;

    to_delete_node = NULL;
    free(to_delete_node);
  }
}

/**
 * Return value n from back(end)
 */
int ll_value_at_from_back(linked_list *ll, int indexFromBack) {
  if (ll->head == NULL) return;
  return ll_value_at(ll, ll_size(ll) - indexFromBack);
}

/**
 * Find and remove an item
 */
void ll_remove(linked_list *ll, int value) {

  int size = ll_size(ll);
  if (size == 0) return;

  Node *to_remove = ll->head;

  int counter = 0;

  while (counter < size) {
    if (to_remove->data == value) {
      ll_erase(ll, counter);
      break;
    } else {
      to_remove = to_remove->next;
    }
    counter++;
  }
}

/**
 * Reverse linked_list
 */
void ll_reverse(linked_list *ll) {

  int size = ll_size(ll);
  if (size == 0 || size == 1) return;

  Node *previous = 0;
  Node *current = ll->head;
  Node *next = 0;

  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  ll->head = previous;
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
