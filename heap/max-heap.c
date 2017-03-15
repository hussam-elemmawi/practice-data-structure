//
// Created by hussamelemmawi on 15/03/17.
//

#include "max-heap.h"
#include <stdlib.h>

MaxHeap *create(int capacity) {
  MaxHeap *new_heap = malloc(sizeof(MaxHeap));
  new_heap->capacity = capacity;
  new_heap->size = 0;
  return new_heap;
}

void destroy(MaxHeap *maxHeap) {
  free(maxHeap->elements);
  free(maxHeap);
}

int pow(int x, int n) {
  if (n > 0) {
    return x * pow(x, n - 1);
  } else return 1;
}

void print_heap(MaxHeap *heap, int nodeIndex) {
  for (int i = 1; i <= heap->size; i++) {
    if (i <= heap->size) printf("%d\t", heap->elements[i]);
  }
}

void insert(MaxHeap *maxHeap, int value) {
  if (maxHeap->size == maxHeap->capacity) {
    printf("Cannot add more elements!\n");
    return;
  } else {
    maxHeap->size++;
    maxHeap->elements[maxHeap->size] = value;
    int nodeIndex = maxHeap->size;
    int parent = maxHeap->size / 2;

    // save max heap property
    while (parent > 0) {
      if (maxHeap->elements[nodeIndex] > maxHeap->elements[parent]) {
        // swap
        int tmp = maxHeap->elements[nodeIndex];
        maxHeap->elements[nodeIndex] = maxHeap->elements[parent];
        maxHeap->elements[parent] = tmp;
      }
      nodeIndex = parent;
      parent = parent / 2;
    }
  }
}

void delete(MaxHeap *maxHeap, int value) {
  if (maxHeap->size == 0) return;

  int nodeIndex = 0;
  for (int i = 1; i <= maxHeap->size; ++i) {
    if (maxHeap->elements[i] == value) {
      nodeIndex = i;
      break;
    }
  }

  // replace with the last value in the heap
  maxHeap->elements[nodeIndex] = maxHeap->elements[maxHeap->size];

  // mark this place as unused with 0 or any number indicating that
  maxHeap->elements[maxHeap->size] = 0;
  maxHeap->size--;

  // save max heap property
  max_heapify(maxHeap, nodeIndex);
}

MaxHeap *heapify(int *arr, int arr_size) {
  MaxHeap *maxHeap = create(arr_size + 1);
  for (int i = 1; i <= arr_size; ++i) {
    insert(maxHeap, arr[i]);
  }
  return maxHeap;
}

// Maintain max heap property
void max_heapify(MaxHeap *maxHeap, int nodeIndex) {
  if (nodeIndex >= maxHeap->size || nodeIndex <= 0) return;

  int parent = maxHeap->elements[nodeIndex];
  int leftChildIndex = nodeIndex * 2 <= maxHeap->size ? nodeIndex * 2 : -1;
  int rightChildIndex = nodeIndex * 2 + 1 <= maxHeap->size ? nodeIndex * 2 + 1 : -1;

  // if there is no children, so this is a leaf node
  // leaf node is a max heap, we are done!
  if (leftChildIndex == -1 && rightChildIndex == -1) {
    return;
  } else
    // if there is two children
  if (leftChildIndex >= 0 && rightChildIndex >= 0) {
    int leftChild = maxHeap->elements[leftChildIndex];
    int rightChild = maxHeap->elements[rightChildIndex];
    // if parent is smaller than left or right child
    if (parent < leftChild || parent < rightChild) {
      int goLeft = leftChild > rightChild ? 1 : 0;

      // if smaller than left
      if (goLeft) { // swap and go left
        int tmp = leftChild;
        maxHeap->elements[leftChildIndex] = parent;
        maxHeap->elements[nodeIndex] = tmp;
        max_heapify(maxHeap, nodeIndex * 2);
      }
        // if not left, so it is right :)
      else { // swap and go right
        int tmp = rightChild;
        maxHeap->elements[rightChildIndex] = parent;
        maxHeap->elements[nodeIndex] = tmp;
        max_heapify(maxHeap, nodeIndex * 2 + 1);
      }
    }
  } else
    // if there is only a left child, then check left
  if (leftChildIndex >= 0) {
    int leftChild = maxHeap->elements[leftChildIndex];
    if (parent < leftChild) { // swap and go left
      int tmp = leftChild;
      leftChild = parent;
      parent = tmp;
      max_heapify(maxHeap, nodeIndex * 2);
    }
  } else
    // if there is only a right child, then check right
  if (rightChildIndex >= 0) {
    int rightChild = maxHeap->elements[rightChildIndex];
    if (parent < rightChild) { // swap and go right
      int tmp = rightChild;
      rightChild = parent;
      parent = tmp;
      max_heapify(maxHeap, nodeIndex * 2 + 1);
    }
  }
}
