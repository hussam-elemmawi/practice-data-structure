//
// Created by hussamelemmawi on 31/01/17.
//

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue_create() {
  Queue *new_queue = malloc(sizeof(Queue));
  check_address(new_queue);

  new_queue->head = NULL;
  new_queue->tail = NULL;

  return new_queue;
}

void queue_destroy(Queue *queue) {
  if (!queue_is_empty(queue)) {
    Node *current = queue->head;

    while (current) {
      queue->head = current->next;
      current = NULL;
      free(current);
      current = queue->head;
    }
    queue = NULL;
    free(queue);
  }
}

void queue_enqueue(Queue *queue, int item) {

  Node *new_node = malloc(sizeof(Node));
  new_node->data = item;

  if (queue_is_empty(queue)) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
}

int queue_deque(Queue *queue) {
  if (!queue_is_empty(queue)) {
    int return_value = queue->head->data;
    Node *to_delete = queue->head;
    queue->head = queue->head->next;
    to_delete = NULL;
    free(to_delete);
    return return_value;
  } else {
    printf("Queue is empty, Nothing to deque");
    return -1;
  }
}

int queue_is_empty(Queue *queue) {
  return queue->head == NULL;
}

void queue_print(Queue *queue) {
  if (!queue_is_empty(queue)) {
    Node *current = queue->head;
    while (current) {
      printf("%d \t", current->data);
      current = current->next;
    }
    printf("\n");
  } else {
    printf("Queue is empty, Nothing to print");
  }
}

void check_address(void *p) {
  return p == NULL ? 1 : 0;
}
