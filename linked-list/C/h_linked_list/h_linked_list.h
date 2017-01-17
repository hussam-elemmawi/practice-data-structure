//
// Created by hussamelemmawi on 17/01/17.
//

#ifndef H_LINKED_LIST
#define H_LINKED_LIST

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct linked_list {
    struct node *head;
    int size;
} H_linked_list;

// Create new H_linked_list
H_linked_list *h_ll_create_new();

// Check address for a pointer
void check_address(void *p);

// Destroy H_linked_list
void h_ll_destroy(H_linked_list *h_ll);

// Returns the size of the H_linked_list
int h_ll_size(H_linked_list *h_ll);

// Returns true(1) if H_linked_list is empty
int h_ll_is_empty(H_linked_list *h_ll);

// Returns the value at specified index
int h_ll_value_at(H_linked_list *h_ll, int index);

// Push an item to the front of the H_linked_list (right after the head)
void h_ll_push_front(H_linked_list *h_ll, int item);

// Prints the H_linked_list
void h_ll_print(H_linked_list *h_ll);


//////////////// tests ////////////////

// Run all tests
void run_all_tests();

// Test size
void test_size();

// Test value at
void test_value_at();

#endif //H_LINKED_LIST
