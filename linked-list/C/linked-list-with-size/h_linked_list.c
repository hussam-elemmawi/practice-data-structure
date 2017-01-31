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

    current = NULL;
    free(current);
    current = next;
  }

  h_ll = NULL;
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
  Node *new_node = malloc(sizeof(struct node));
  new_node->next = h_ll->head;
  new_node->data = item;

  h_ll->head = new_node;
  h_ll->size++;
}

/**
 * Prints the H_linked_list
 */
void h_ll_print(H_linked_list *h_ll) {

  if (h_ll->size == 0) {
    printf("Nothing to print\n");
    return;
  }

  Node *move = h_ll->head;
  int counter = 0;
  while (move && counter < h_ll->size) {
    printf(" %d", move->data);
    move = move->next;
    counter++;
  }
}

/**
 * Push an item to the back of the H_linked_list
 */
void h_ll_push_back(H_linked_list *h_ll, int item) {

  Node *new_node = malloc(sizeof(struct node));
  new_node->next = 0;
  new_node->data = item;

  if (h_ll->size == 0) {
    h_ll->head = new_node;
    new_node->data = item;
  } else {
    Node *current = h_ll->head;
    int size = h_ll->size;
    // Initialize the counter with 1 as it is already pointing to the head node
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

/**
 * Pop an item from the front(start) of H_linked_list
 */
int h_ll_pop_front(H_linked_list *h_ll) {

  int value = h_ll->head->data;
  Node *nodeToPop = h_ll->head;
  h_ll->head = nodeToPop->next;

  nodeToPop = NULL;
  free(nodeToPop);
  h_ll->size--;
  return value;
}

/**
 * Pop an item from the back of H_linked_list
 */
int h_ll_pop_back(H_linked_list *h_ll) {

  if (h_ll->size == 0) return;

  Node *current = h_ll->head;
  int size = h_ll->size;
  int counter = 0;

  while (counter < size - 1) {
    current = current->next;
    counter++;
  }

  int value = current->data;

  current = NULL;
  free(current);
  h_ll->size--;

  return value;
}

/**
 * Return the value on the front(start) of H_linked_list
 */
int h_ll_front(H_linked_list *h_ll) {
  return h_ll_value_at(h_ll, 0);
}

/**
 * Return the value on the back(end) of H_linked_list
 */
int h_ll_back(H_linked_list *h_ll) {
  return h_ll_value_at(h_ll, h_ll->size - 1);
}

/**
 * Insert value at index
 */
void h_ll_insert(H_linked_list *h_ll, int index, int value) {

  int size = h_ll->size;
  if (index > size || index < 0) return;
  if (index == 0) h_ll_push_front(h_ll, value);
  else if (index == size) h_ll_push_back(h_ll, value);
  else {

    Node *new_node = (Node *) malloc(sizeof(struct node));
    new_node->data = value;
    // The allocation happens inside the linked list!
    // while initializing this new node the list linking breaks!
//    new_node->next = 0;

    int counter = 0;
    Node *previous_node = h_ll->head;
    Node *next_node = previous_node->next;

    while (counter < index) {
      counter++;
      previous_node = previous_node->next;
    }

    next_node = previous_node->next;
    previous_node->next = new_node;
    new_node->next = next_node;

    h_ll->size++;
  }
}

/**
 * Erase value at index
 */
void h_ll_erase(H_linked_list *h_ll, int index) {

  int size = h_ll->size;
  if (size == 0 || index >= size) return;
  if (index == 0) {
    h_ll_pop_front(h_ll);
  } else if (index == size - 1) {
    h_ll_pop_back(h_ll);
  } else {

    int counter = 0;
    Node *previous_node = h_ll->head;
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
    h_ll->size--;
  }
}

/**
 * Return value n from back(end)
 */
int h_ll_value_at_from_back(H_linked_list *h_ll, int indexFromBack) {
  if (h_ll->size == 0) return;
  return h_ll_value_at(h_ll, h_ll->size - indexFromBack);
}

/**
 * Find and remove an item
 */
void h_ll_remove(H_linked_list *h_ll, int value) {

  int size = h_ll->size;
  if (size == 0) return;

  Node *to_remove = h_ll->head;

  int counter = 0;

  while (counter < size) {
    if (to_remove->data == value) {
      h_ll_erase(h_ll, counter);
      break;
    } else {
      to_remove = to_remove->next;
    }
    counter++;
  }
}

/**
 * Reverse H_linked_list
 */
void h_ll_reverse(H_linked_list *h_ll) {

  if (h_ll->size == 0 || h_ll->size == 1) return;

  Node *previous = 0;
  Node *current = h_ll->head;
  Node *next = 0;

  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  h_ll->head = previous;
}