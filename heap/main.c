#include <stdio.h>
#include "max-heap.c"

int main() {
  MaxHeap *maxHeap = create(10);
  print_heap(maxHeap, 0);
  insert(maxHeap, 2);
  insert(maxHeap, 4);
  insert(maxHeap, 1);
  insert(maxHeap, 5);
  insert(maxHeap, 6);
  insert(maxHeap, 0);
  insert(maxHeap, -4);
  insert(maxHeap, -3);
  insert(maxHeap, -1);
  print_heap(maxHeap, 0);
  printf("\n");

  delete(maxHeap, -3);
  printf("after deleting -3\n");
  print_heap(maxHeap, 0);
  printf("\n");

  delete(maxHeap, 5);
  printf("after deleting 5\n");
  print_heap(maxHeap, 0);
  printf("\n");

  printf("max: %d\n", get_max(maxHeap));
  printf("extract_max: %d\n", extract_max(maxHeap));
  printf("max: %d\n", get_max(maxHeap));

  return 0;
}