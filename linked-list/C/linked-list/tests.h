//
// Created by hussamelemmawi on 23/01/17.
//

#ifndef LINKEDLIST_TESTS_H
#define LINKEDLIST_TESTS_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[01m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

int tests_number = 13;

// Run all tests
void run_all_tests();

// Test size
void test_size();

// Test value at
void test_value_at();

// Test is the H_linked_list empty
void test_is_empty();

// Test push back
void test_push_back();

// Test pop front
void test_pop_front();

// Test pop back
void test_pop_back();

// Test get front item
void test_front();

// Test get back item
void test_back();

// Test insertion
void test_insert();

// Test erase
void test_erase();

// Test returning value n from back(end)
void test_value_from_back();

// Test remove value
void test_remove();

// Test reverse H_linked_list
void test_reverse();

// Helper function
void print_passed();

#endif //LINKEDLIST_TESTS_H
