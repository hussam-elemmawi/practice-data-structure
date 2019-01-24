//
// Created by hussamelemmawi on 30/01/17.
//

#ifndef STACK_LINKED_LIST_TEST_H
#define STACK_LINKED_LIST_TEST_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[01m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

int tests_number = 4;

// Run all tests
void run_all_tests();

void test_push();

void test_pop();

void test_top();

void test_is_empty();

#endif //STACK_LINKED_LIST_TEST_H
