//
// Created by hussamelemmawi on 04/01/17.
//

#ifndef RESIZEABLE_ARRAY_H
#define RESIZEABLE_ARRAY_H

const int MIN_CAPACITY = 16;
const int GROWTH_FACTOR = 2;
const int SHRINK_FACTOR = 4;


typedef struct hussam_resizeable_array_implement {

  int size;
  int capacity;
  int *data;
} R_Array;

// Array functions

// Create a new R_Array with default capacity
R_Array *r_array_create(int capacity);

// Destroy R_Array
void r_array_destroy(R_Array *arr);

// Check capacity
int check_capacity(int capacity);

// Checks to see if given value is valid for memory allocating, and exits if so
void check_address(void *p);

// Add an item to end of the R_Array
void r_array_push(R_Array *arr, int item);

// Remove an item to end of the R_Array
int r_array_pop(R_Array *arr);

// Resize array if needed
void r_array_resize_if_needed(R_Array *arr, int needed_size);

// Grow R_Array size by Growth factor
void r_array_grow(R_Array *arr);

// Shrink R_Array size by Growth factor
void r_array_shrink(R_Array *arr);

// Return R_Array size
int r_array_size(R_Array *arr);

// Return R_Array capacity
int r_array_capacity(R_Array *arr);

// Check if R_Array is empty
int r_array_is_empty(R_Array *arr);

// Return item at index
int r_array_at(R_Array *arr, int index);

// Delete item at index
void r_array_delete(R_Array *arr, int index);

// Insert item into index
void r_array_insert(R_Array *arr, int index, int item);

// Prepend (insert at index 0) item into index
void r_array_prepend(R_Array *arr, int item);

// Find item and returns its index
int r_array_find(R_Array *arr, int item);

// Remove index of a value (even if in multiple places)
void r_array_remove(R_Array *arr, int item);

// Set an item to a given value
void r_array_set(R_Array *arr, int index, int value);

// Print R_Array
void r_array_print(R_Array *arr);

// tests

void run_all_tests();

void test_size_init();
void test_push();
void test_pop();
void test_prepend();
void test_empty();
void test_resize();
void test_capacity();
void test_append_past_capacity();
void test_at();
void test_insert();
void test_remove();
void test_find_exists();
void test_find_not_exists();


#endif // RESIZEABLE_ARRAY_H
















