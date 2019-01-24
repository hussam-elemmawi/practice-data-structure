//
// Created by hussamelemmawi on 01/02/17.
//

#include "queue.h"
#include "stdlib.h"
#include "stdio.h"

Queue *queue_create(int capacity) {
  Queue *queue = malloc(sizeof(Queue));

  if (queue == NULL) {
    exit(EXIT_FAILURE);
  }

  queue->capacity = capacity + 1;
  queue->read = 0;
  queue->write = 0;

  queue->array = (int *) malloc(sizeof(int) * (capacity + 1));

  return queue;
}

void queue_destroy(Queue *queue) {
  queue->array = NULL;
  free(queue->array);
  queue = NULL;
  free(queue);
}

void queue_enqueue(Queue *queue, int item) {
  if (!queue_is_full(queue)) {
    queue->array[queue->write++] = item;
    queue->write %= queue->capacity;
  } else {
    printf("Queue is full, cannot enqueue.\n");
  }
}

int queue_deque(Queue *queue) {
  if (!queue_is_empty(queue)) {
    int return_value = queue->array[queue->read];
    queue->read++;
    queue->read %= queue->capacity;
    return return_value;
  }
  exit(EXIT_FAILURE);
}

int queue_is_empty(Queue *queue) {
  return queue->write == queue->read;
}

int queue_is_full(Queue *queue) {
  return ((queue->write + 1) % queue->capacity) == queue->read;
}

void queue_print(Queue *queue) {
  if (!queue_is_empty(queue)) {
    if (queue->write > queue->read) {
      for (int i = queue->read; i < queue->write; ++i) {
        printf("%d \t", queue->array[i]);
      }
    } else {
      int i = queue->read;
      do {

        printf("%d \t", queue->array[i++]);
        i %= queue->capacity;

      } while (i != queue->write);
    }
    printf("\n");
  }
}