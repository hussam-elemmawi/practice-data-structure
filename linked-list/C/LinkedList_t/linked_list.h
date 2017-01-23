//
// Created by hussamelemmawi on 23/01/17.
//

#ifndef LINKEDLIST_T_LINKED_LIST_T_H
#define LINKEDLIST_T_LINKED_LIST_T_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linked_list {
    struct node *head;
    struct node *tail;
} linked_list;

// Create new H_linked_list
linked_list *ll_create_new();

// Check address for a pointer
void check_address(void *p);

// Destroy H_linked_list
void ll_destroy(linked_list *ll);

// Returns the size of the H_linked_list
int ll_size(linked_list *ll);

// Returns true(1) if H_linked_list is empty
int ll_is_empty(linked_list *ll);

// Returns the value at specified index
int ll_value_at(linked_list *ll, int index);

// Push an item to the front(start) of the H_linked_list (right after the head)
void ll_push_front(linked_list *ll, int item);

// Prints the H_linked_list
void ll_print(linked_list *ll);

// Push an item to the back(end) of the H_linked_list
void ll_push_back(linked_list *ll, int item);

// Pop an item from the front(start) of H_linked_list
int ll_pop_front(linked_list *ll);

// Return the value on the front(start) of H_linked_list
int ll_front();

// Return the value on the back(end) of H_linked_list
int ll_back();

// Insert value at index
void ll_insert(linked_list *ll, int index, int value);

// Erase value at index
void ll_erase(linked_list *ll, int index);

// Return value n from back(end)
int ll_value_at_from_back(linked_list *ll, int indexFromBack);

// Find and remove an item
void ll_remove(linked_list *ll, int value);

// Reverse H_linked_list
void ll_reverse(linked_list *ll);

#endif //LINKEDLIST_T_LINKED_LIST_T_H
