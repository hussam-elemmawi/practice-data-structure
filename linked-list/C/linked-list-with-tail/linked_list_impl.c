//
// Created by hussamelemmawi on 23/01/17.
//

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

  new_ll->head = NULL;
  new_ll->tail = NULL;
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
  return ll->head == NULL && ll->tail == NULL ? 1 : 0;
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

  if (ll->head == NULL) {
    ll->head = new_node;
    ll->tail = new_node;
  } else {
    ll->head = new_node;
  }
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
  printf("\n");
}

/**
 * Push an item to the back of the linked_list
 */
void ll_push_back(linked_list *ll, int item) {

  Node *new_node = malloc(sizeof(Node));
  new_node->data = item;
  new_node->next = NULL;

  if (ll->head == NULL) {
    // This is the first element
    ll->tail = new_node;
    ll->head = new_node;
  } else {
    ll->tail->next = new_node;
    ll->tail = new_node;
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

  while (current->next != ll->tail) {
    current = current->next;
  }

  int value = ll->tail->data;
  ll->tail = current;
  current->next = NULL;
  free(current->next);
  return value;
}

/**
 * Return the value on the front(start) of linked_list
 */
int ll_front(linked_list *ll) {
  if (ll->head == NULL) return;
  else
    return ll->head->data;
}

/**
 * Return the value on the back(end) of linked_list
 */
int ll_back(linked_list *ll) {

  if (ll->head == NULL) return;
  else
    return ll->tail->data;
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

  // Redirecting the node's next pointer
  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  ll->tail = ll->head;
  ll->head = previous;
}
