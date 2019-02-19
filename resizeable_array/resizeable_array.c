//
// Created by hussamelemmawi on 04/01/17.
//
// R_Array functions implementation

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "resizeable_array.h"

/**
 * Create a new R_Array with default capacity
 */
R_Array *r_array_create(int capacity) {

  capacity = check_capacity(capacity);

  R_Array *arr = malloc(sizeof(R_Array));
  check_address(arr);

  arr->data = (int *) malloc(sizeof(int) * capacity);
  check_address(arr->data);

  arr->size = 0;
  arr->capacity = capacity;

  // For debuging
  printf("Done creating new R_Array with capacity of %d!\n", arr->capacity);

  return arr;
}

/**
 * Determine capacity from given one
 */
int check_capacity(int capacity) {

  if (capacity <= 0) {
    printf("ERROR: Capacity can not be equal or less than 0!\n");
    printf("Changing capacity to 1.\n");
    capacity = 1;
  }

  return capacity;
}

/**
 * Check address of a pointer
 */
void check_address(void *p) {
  if (NULL == p) {
    printf("Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
}

/**
* Destroy a R_Array
*/
void r_array_destroy(R_Array *arr) {
  free(arr->data);
  free(arr);

  // For debuging
  printf("\nDone destroying R_Array!\n");
}

/**
 * Add new item to the end of the R_Array
 */
void r_array_push(R_Array *arr, int item) {

  // should check resizing needed here or not
  r_array_resize_if_needed(arr, arr->size + 1);

  *(arr->data + arr->size) = item;
  ++(arr->size);
  printf("%d pushed\n", item);
}

/**
 * Add new item to the end of the R_Array
 */
int r_array_pop(R_Array *arr) {

  if (arr->size <= 0) {
    printf("Size = 0, Nothing to pop\n");
    return 404;
  }

  // should check resizing needed here or not
  r_array_resize_if_needed(arr, arr->size - 1);

  int poped_item = *(arr->data + arr->size - 1);
  arr->size--;

  printf("%d poped, size = %d\n", poped_item, arr->size);

  return poped_item;
}

/**
 * Add new item to the end of the R_Array
 */
void r_array_resize_if_needed(R_Array *arr, int needed_size) {

  if (arr->size < needed_size) { // growing
    if (arr->size == arr->capacity) {
      r_array_grow(arr);
    }
  } else if (arr->size > needed_size) {
    if (arr->size < arr->capacity / SHRINK_FACTOR) { // shrinking
      r_array_shrink(arr);
    }
  } // if equal, do nothing
}

/**
 * Grow R_Array size by Growth factor
 */
void r_array_grow(R_Array *arr) {

  int old_capacity = arr->capacity;
  int new_capacity = check_capacity(arr->capacity * GROWTH_FACTOR);
  int *new_data = (int *) malloc(sizeof(int) * new_capacity);
  check_address(new_data);

  for (int i = 0; i < old_capacity; i++)
    *(new_data + i) = *(arr->data + i);

  free(arr->data);
  arr->data = new_data;

  arr->capacity = new_capacity;

  printf("R_Array grows to be %d elements capacity\n", arr->capacity);

}

/**
 * Shrink R_Array size by Growth factor
 */
void r_array_shrink(R_Array *arr) {

  int old_capacity = arr->capacity;
  int new_capacity = check_capacity(arr->capacity / SHRINK_FACTOR);

  if (new_capacity == 0) {
    printf("Capacity cannot be 0, changing to 1.\n");
  }

  if (new_capacity != old_capacity) {

    int *new_arr = (int *) malloc(sizeof(int) * new_capacity);

    check_address(new_arr);

    for (int i = 0; i < arr->size; i++) {
      *(new_arr + i) = *(arr->data + i);
    }

    free(arr->data);

    arr->data = new_arr;
    arr->capacity = new_capacity;

    printf("R_Array shrinks to be %d elements capacity\n", arr->capacity);

  }
}

/**
 * Return R_Array size
 */
int r_array_size(R_Array *arr) {

  return arr->size;
}

/**
 * Return R_Array capacity
 */
int r_array_capacity(R_Array *arr) {

  return arr->capacity;
}

/**
 * Check if R_Array is empty
 */
int r_array_is_empty(R_Array *arr) {

  return arr->size == 0 ? 1 : 0;
}

/**
 * Return item at index
 */
int r_array_at(R_Array *arr, int index) {

  check_address(arr + index);

  if (index < 0 || index >= arr->size) {

    printf("R_Array out of bounds, %d index not found.\n", index);
    return 404;
  }

  return *(arr->data + index);
}

/**
 * Delete item at index
 */
void r_array_delete(R_Array *arr, int index) {

  check_address(arr + index);

  if (index < 0 || index >= arr->size) {

    printf("Requested index for deletion is out of bounds");
    exit(EXIT_FAILURE);
  }

  for (int i = index; i < arr->size - 1; i++) {
    *(arr->data + i) = *(arr->data + i + 1);
  }

  arr->size--;

  // should check resizing needed here or not
  r_array_resize_if_needed(arr, arr->size);

  printf("item deleted from index %d\n", index);
}

/**
 * Insert item into index
 */
void r_array_insert(R_Array *arr, int index, int item) {

  check_address(arr + index);

  if (index < 0) {
    printf("Requested index for insertion is out of bounds");
    return;
  }

  // should check resizing needed here or not
  r_array_resize_if_needed(arr, arr->size + 1);

  for (int i = arr->size - 1; i > index; --i) {
    *(arr->data + i) = *(arr->data + i - 1);
  }

  *(arr->data + index) = item;

  arr->size++;

  printf("%d inserted into index %d\n", item, index);
}

/**
 * Prepend (insert at index 0) item into index
 */
void r_array_prepend(R_Array *arr, int item) {
  r_array_insert(arr, 0, item);
}

/**
 * Find item and returns its index, -1 otherwise.
 */
int r_array_find(R_Array *arr, int item) {

  for (int i = 0; i < arr->size; i++) {
    if (*(arr->data + i) == item) {
      printf("%d Found at %d\n", item, i);
      return i;
    }
  }
  printf("%d not found\n", item);
  return -1;
}

/**
 * Remove index of a value (even if in multiple places)
 */
void r_array_remove(R_Array *arr, int item) {
  int found_at = -1;
  do {
    found_at = r_array_find(arr, item);

    if (found_at != -1) {
      r_array_delete(arr, found_at);
    }
  } while (found_at != -1);
}

/**
 * Set an item to a given value
 */
void r_array_set(R_Array *arr, int index, int value) {
  *(arr->data + index) = value;
}

void r_array_print(R_Array *arr) {
  if (arr->size == 0) {
    printf("Nothing to print!\n");
    return;
  }

  printf("Printing R_Array\n");
  for (int i = 0; i < arr->size; i++)
    printf("%d\t", r_array_at(arr, i));
  printf("\n");
}

// Tests ---------------------------------


/**
 * Function to run all tests at once
 */
void run_all_tests() {
  test_size_init();
  test_push();
  test_pop();
  test_prepend();
  test_empty();
  test_resize();
  test_at();
  test_insert();
  test_remove();
  test_find_exists();
  test_find_not_exists();
}

void test_size_init() {
  printf("***** test_size_init *****\n");
  R_Array *arr = r_array_create(1);

  assert(arr->size == 0);

  r_array_push(arr, 5);
  assert(arr->size == 1);

  r_array_push(arr, 6);
  assert(arr->size == 2);


  r_array_pop(arr);
  r_array_pop(arr);
  assert(arr->size == 0);

  r_array_pop(arr);
  assert(arr->size == 0);

  r_array_destroy(arr);
  printf("\n");
}

void test_push() {
  printf("***** test_push *****\n");
  R_Array *arr = r_array_create(2);

  r_array_push(arr, 1);
  assert(r_array_size(arr) == 1);
  assert(r_array_at(arr, 0) == 1);

  printf("\n");
}

void test_pop() {
  printf("***** test_pop *****\n");
  R_Array *arr = r_array_create(1);

  r_array_push(arr, 1);
  assert(r_array_size(arr) == 1);
  assert(r_array_pop(arr) == 1);

  printf("\n");
}

void test_prepend() {
  printf("***** test_prepend *****\n");
  R_Array *arr = r_array_create(16);
  r_array_prepend(arr, 5);
  r_array_push(arr, 4);
  r_array_push(arr, 3);

  assert(arr->size == 3);
  assert(r_array_at(arr, 0) == 5);
  assert(r_array_at(arr, 1) == 4);
  assert(r_array_at(arr, 2) == 3);
  r_array_destroy(arr);
  printf("\n");
}

void test_empty() {
  printf("***** test_empty *****\n");
  R_Array *arr = r_array_create(2);
  assert(r_array_is_empty(arr) == 1);

  r_array_push(arr, 5);
  assert(r_array_is_empty(arr) == 0);

  r_array_destroy(arr);
  printf("\n");
}

void test_resize() {
  printf("***** test_resize *****\n");
  R_Array *arr = r_array_create(3);
  r_array_push(arr, 1);
  r_array_push(arr, 2);
  r_array_push(arr, 3);
  assert(r_array_capacity(arr) == 3);

  r_array_push(arr, 4);
  assert(r_array_capacity(arr) == 6);

  for (int i = 0; i < 3; i++)
    r_array_push(arr, i + 1);
  assert(r_array_capacity(arr) == 12);

  // force shrink by making size < 12 / 4 = 3
  for (int i = 0; i < 10; i++)
    r_array_pop(arr);
  assert(r_array_capacity(arr) == 3);

  r_array_destroy(arr);
  printf("\n");
}

void test_at() {
  printf("***** test_at *****\n");
  R_Array *arr = r_array_create(3);

  r_array_push(arr, 1);
  assert(r_array_at(arr, 0) == 1);

  r_array_push(arr, 2);
  assert(r_array_at(arr, 1) == 2);

  r_array_pop(arr);
  assert(r_array_at(arr, 1));

  r_array_destroy(arr);
  printf("\n");
}

void test_insert() {
  printf("***** test_insert *****\n");
  R_Array *arr = r_array_create(10);

  for (int i = 0; i < 16; i++)
    r_array_insert(arr, i, i);

  r_array_print(arr);

  for (int i = 0; i < 16; i++)
    assert(r_array_at(arr, i) == i);

  r_array_destroy(arr);
  printf("\n");
}

void test_remove() {
  printf("***** test_remove *****\n");
  R_Array *arr = r_array_create(10);

  r_array_push(arr, 5);
  r_array_push(arr, 5);
  r_array_push(arr, 5);

  r_array_remove(arr, 5);
  assert(r_array_size(arr) == 0);

  r_array_push(arr, 5);
  r_array_push(arr, 4);

  r_array_remove(arr, 5);
  assert(r_array_size(arr) == 1);

  r_array_destroy(arr);
  printf("\n");
}

void test_find_exists() {
  printf("***** test_find_exists *****\n");
  R_Array *arr = r_array_create(10);

  r_array_insert(arr, 0, 2);
  r_array_insert(arr, 1, 4);
  r_array_insert(arr, 2, 8);

  assert(r_array_find(arr, 2) == 0);
  assert(r_array_find(arr, 8) == 2);

  r_array_destroy(arr);
  printf("\n");
}

void test_find_not_exists() {
  printf("***** test_find_not_exists *****\n");
  R_Array *arr = r_array_create(10);

  r_array_insert(arr, 0, 2);
  r_array_insert(arr, 1, 4);
  r_array_insert(arr, 2, 8);

  assert(r_array_find(arr, 7) == -1);

  r_array_destroy(arr);
  printf("\n");
}