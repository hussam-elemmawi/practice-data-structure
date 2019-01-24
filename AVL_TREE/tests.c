//
// Created by hussamelemmawi on 09/03/17.
//

#include "tests.h"
#include "binary-search-tree.c"
#include <assert.h>

int passed_test = 0;

// Run all tests
void run_all_tests() {
  test_get_node_count();
  passed_test++;

  test_print_inOrder();
  passed_test++;

  test_find();
  passed_test++;

  test_find_min();
  passed_test++;

  test_find_max();
  passed_test++;

  test_height_of();
  passed_test++;

  test_insert();
  passed_test++;

  test_delete();
  passed_test++;

  test_get_successor();
  passed_test++;

  print_final_result();
}

// Test get tree size
void test_get_node_count() {
  BST *bst = create(5);
  assert(get_node_count(bst->root) == 1);

  insert(bst->root, 1);
  assert(get_node_count(bst->root) == 2);

  destroy_node(bst->root);
  print_passed("test_get_node_count");
}

// Test inorder traversal
int test_print_inOrder() {
  BST *bst = create(2);
  assert(get_node_count(bst->root) == 1);

  insert(bst->root, 1);
  insert(bst->root, 3);
  print_inOrder(bst->root);
  printf("\n");

  destroy_node(bst->root);
  print_passed("test_print_inOrder");
}

// Test find
void test_find() {
  BST *bst = create(5);

  insert(bst->root, 1);
  assert(find(bst->root, 1)->value == 1);
  insert(bst->root, 3);
  insert(bst->root, 8);
  assert(find(bst->root, 1)->value == 1);
  assert(find(bst->root, 8)->value == 8);

  delete(bst->root, 8);
  assert(find(bst->root, 8) == NULL);

  destroy_node(bst->root);
  print_passed("test_find");
}

// Test find min
void test_find_min() {
  BST *bst = create(5);

  insert(bst->root, 1);
  assert(find_min(bst->root)->value == 1);
  delete(bst->root, 1);

  insert(bst->root, 6);
  assert(find_min(bst->root)->value == 5);

  destroy_node(bst->root);
  print_passed("test_find_min");
}

// Test find max
void test_find_max() {
  BST *bst = create(5);

  insert(bst->root, 1);
  assert(find_max(bst->root)->value == 5);
  delete(bst->root, 1);

  insert(bst->root, 6);
  assert(find_max(bst->root)->value == 6);

  destroy_node(bst->root);
  print_passed("test_find_max");
}

// Test get height of tree
void test_height_of() {
  BST *bst = create(5);
  assert(height_of(bst->root) == 1);

  insert(bst->root, 1);
  assert(height_of(bst->root) == 2);
  delete(bst->root, 1);
  assert(height_of(bst->root) == 1);

  insert(bst->root, 6);
  insert(bst->root, 2);
  assert(height_of(bst->root) == 2);

  insert(bst->root, 7);
  assert(height_of(bst->root) == 3);

  destroy_node(bst->root);
  print_passed("test_height_of");
}

// Test insert
void test_insert() {
  BST *bst = create(5);
  assert(find(bst->root, 5) != NULL);

  insert(bst->root, 6);
  insert(bst->root, 2);
  insert(bst->root, 3);
  insert(bst->root, 7);
  assert(find(bst->root, 2) != NULL);
  assert(find(bst->root, 6) != NULL);
  assert(find(bst->root, 7) != NULL);

  delete(bst->root, 3);
  delete(bst->root, 7);
  assert(find(bst->root, 6) != NULL);
  assert(find(bst->root, 7) == NULL);

  destroy_node(bst->root);
  print_passed("test_insert");
}

// Test delete
void test_delete() {
  BST *bst = create(5);
  assert(find(bst->root, 5) != NULL);

  insert(bst->root, 6);
  insert(bst->root, 2);
  insert(bst->root, 3);
  insert(bst->root, 7);
  assert(find(bst->root, 2) != NULL);
  assert(find(bst->root, 6) != NULL);
  assert(find(bst->root, 7) != NULL);

  delete(bst->root, 3);
  delete(bst->root, 7);
  assert(find(bst->root, 6) != NULL);
  assert(find(bst->root, 7) == NULL);

  delete(bst->root, 5);
  assert(find(bst->root, 5) == NULL);
  print_inOrder(bst->root);
  printf("\n");

  destroy_node(bst->root);
  print_passed("test_delete");
}

// Test get successor
void test_get_successor() {
  BST *bst = create(5);
  assert(find(bst->root, 5) != NULL);

  insert(bst->root, 1);
  insert(bst->root, 2);
  insert(bst->root, 3);
  insert(bst->root, 4);
  insert(bst->root, 6);
  insert(bst->root, 7);
  insert(bst->root, 8);
  insert(bst->root, 9);

  print_inOrder(bst->root);
  printf("\n");

  assert(get_successor(bst->root)->value == 6);
  assert(get_successor(bst->root->right)->value == 7);
  assert(get_successor(bst->root->left)->value == 2);

  destroy_node(bst->root);
  print_passed("test_get_successor");
}

void print_passed(char str[]) {
  printf("%s***** %s *****\n", ANSI_COLOR_BLUE, str);
}

print_final_result() {
  if (passed_test == tests_number)
    printf(" all %d tests passed", tests_number);
  else
    printf(" %d/%d tests passed", passed_test, tests_number);
}