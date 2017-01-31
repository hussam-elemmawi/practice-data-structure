//
// Created by hussamelemmawi on 31/01/17.
//

#ifndef QUEUE_LINKED_LIST_QUEUE_H
#define QUEUE_LINKED_LIST_QUEUE_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *tail;
} Queue;

Queue *queue_create();

void queue_destroy(Queue *queue);

void queue_enqueue(Queue *queue, int item);

int queue_deque(Queue *queue);

int queue_is_empty(Queue *queue);

void queue_print(Queue *queue);

void check_address(void *p);

#endif //QUEUE_LINKED_LIST_QUEUE_H
