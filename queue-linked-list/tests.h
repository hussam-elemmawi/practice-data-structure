//
// Created by hussamelemmawi on 31/01/17.
//

#ifndef QUEUE_LINKED_LIST_TESTS_H
#define QUEUE_LINKED_LIST_TESTS_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[01m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

int tests_number = 3;

// Run all tests
void run_all_tests();

void test_enqueue();

void test_deque();

void test_is_empty();

#endif //QUEUE_LINKED_LIST_TESTS_H
