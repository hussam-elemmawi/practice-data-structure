#include <stdio.h>
#include "resizeable_array.c"

void run_example();

int main() {

  run_example();
//  run_all_tests();

  return 0;
}

void run_example() {
  R_Array *my_arr = r_array_create(16);

  r_array_print(my_arr);

//  for (int i = 0; i < 16; i++)
//    r_array_push(my_arr, i);

  r_array_insert(my_arr, 5, 100);

  r_array_print(my_arr);
//
//  r_array_print(my_arr);
//
//  r_array_push(my_arr, 5);
//
//  r_array_prepend(my_arr, 5);
//
//  r_array_print(my_arr);
//
//  r_array_remove(my_arr, 5);
//
//  r_array_print(my_arr);
//
//  r_array_set(my_arr, 0, 100);
//
//  r_array_print(my_arr);
//
//  int len = my_arr->size;
//
//  for (int j = 0; j < len; ++j) {
//    r_array_pop(my_arr);
//  }
//
//  r_array_print(my_arr);

  r_array_destroy(my_arr);

}