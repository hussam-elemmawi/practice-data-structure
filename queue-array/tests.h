//
// Created by hussamelemmawi on 01/02/17.
//

#ifndef QUEUE_ARRAY_TESTS_H
#define QUEUE_ARRAY_TESTS_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[01m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

const int tests_number = 4;

// Run all tests
void run_all_tests();

void test_enqueue();

void test_deque();

void test_is_empty();

void test_is_full();

#endif //QUEUE_ARRAY_TESTS_H
