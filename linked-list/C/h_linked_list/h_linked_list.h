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

// Push an item to the front(start) of the H_linked_list (right after the head)
void h_ll_push_front(H_linked_list *h_ll, int item);

// Prints the H_linked_list
void h_ll_print(H_linked_list *h_ll);

// Push an item to the back(end) of the H_linked_list
void h_ll_push_back(H_linked_list *h_ll, int item);

// Pop an item from the front(start) of H_linked_list
int h_ll_pop_front(H_linked_list *h_ll);

// Return the value on the front(start) of H_linked_list
int h_ll_front();

// Return the value on the back(end) of H_linked_list
int h_ll_back();

// Insert value at index
void h_ll_insert(H_linked_list *h_ll, int index, int value);

// Erase value at index
void h_ll_erase(H_linked_list *h_ll, int index);

// Return value n from back(end)
int h_ll_value_at_from_back(H_linked_list *h_ll, int indexFromBack);

// Find and remove an item
void h_ll_remove(H_linked_list *h_ll, int value);

// Reverse H_linked_list
void h_ll_reverse(H_linked_list *h_ll);

//////////////// tests ////////////////

// Run all tests
void run_all_tests();

// Test size
void test_size();

// Test value at
void test_value_at();

// Test is the H_linked_list empty
void test_is_empty();

// Test push back
void test_push_back();

// Test pop front
void test_pop_front();

// Test pop back
void test_pop_back();

// Test get front item
void test_front();

// Test get back item
void test_back();

// Test insertion
void test_insert();

// Test erase
void test_erase();

// Test returning value n from back(end)
void test_value_from_back();

// Test remove value
void test_remove();

// Test reverse H_linked_list
void test_reverse();

#endif //H_LINKED_LIST
