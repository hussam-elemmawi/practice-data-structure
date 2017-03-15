//
// Created by hussamelemmawi on 15/03/17.
//

#ifndef HEAP_MAX_HEAP_H
#define HEAP_MAX_HEAP_H

typedef struct max_heap {
    int elements[11];
    int size;
    int capacity;
} MaxHeap;

MaxHeap *create(int capacity);

void destroy(MaxHeap *maxHeap);

void print_heap(MaxHeap *heap, int nodeIndex);

void insert(MaxHeap *maxHeap, int value);

void delete(MaxHeap *maxHeap, int value);

MaxHeap *heapify(int *arr, int arr_size);

// Maintain max heap property
void max_heapify(MaxHeap *maxHeap, int nodeIndex);

#endif //HEAP_MAX_HEAP_H
