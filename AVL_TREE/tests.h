//
// Created by hussamelemmawi on 09/03/17.
//

#ifndef BST_TESTS_H
#define BST_TESTS_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[01m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

int tests_number = 9;

// Run all tests
void run_all_tests();

// Test get tree size
void test_get_node_count();

// Test inorder traversal
int test_print_inorder();

// Test find
void test_find();

// Test find min
void test_find_min();

// Test find max
void test_find_max();

// Test get height of tree
void test_height_of();

// Test insert
void test_insert();

// Test delete
void test_delete();

// Test get successor
void test_get_successor();

#endif //BST_TESTS_H
