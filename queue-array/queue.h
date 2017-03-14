//
// Created by hussamelemmawi on 01/02/17.
//

#ifndef QUEUE_ARRAY_QUEUE_H
#define QUEUE_ARRAY_QUEUE_H

typedef struct queue {
    int read;
    int write;
    int capacity;
    int *array;
} Queue;

Queue *queue_create(int capacity);

void queue_destroy(Queue *queue);

void queue_enqueue(Queue *queue, int item);

int queue_deque(Queue *queue);

int queue_is_empty(Queue *queue);

int queue_is_full(Queue *queue);

void queue_print(Queue *queue);

#endif //QUEUE_ARRAY_QUEUE_H
