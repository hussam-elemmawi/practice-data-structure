#include <stdio.h>
#include "avl_tree.c"

int main() {

//  Insertion test
//  Node *root = NULL;
//
//  root = insert(root, 10);
//  root = insert(root, 20);
//  root = insert(root, 30);
//  root = insert(root, 40);
//  root = insert(root, 50);
//  root = insert(root, 25);
//
//  /* The constructed AVL Tree would be
//           30
//          /  \
//        20   40
//       /  \     \
//      10  25    50
// */
//  print_preOrder(root);


  // Deletion test
  Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 9);
  print_preOrder(root);
  printf("after insert 9\n");
  root = insert(root, 5);
  print_preOrder(root);
  printf("after insert 5\n");
  root = insert(root, 10);
  print_preOrder(root);
  printf("after insert 10\n");
  root = insert(root, 0);
  print_preOrder(root);
  printf("after insert 0\n");
  root = insert(root, 6);
  print_preOrder(root);
  printf("after insert 6\n");
  root = insert(root, 11);
  print_preOrder(root);
  printf("after insert 11\n");
  root = insert(root, -1);
  print_preOrder(root);
  printf("after insert -1\n");
  root = insert(root, 1);
  print_preOrder(root);
  printf("after insert 1\n");
  root = insert(root, 2);
  print_preOrder(root);
  printf("after insert 2\n");

  /* The constructed AVL Tree would be
          9
         /  \
        1    10
      /  \     \
     0    5     11
    /    /  \
   -1   2    6
  */

  printf("Preorder traversal of the constructed AVL "
           "tree is \n");
  print_preOrder(root);

  root = delete(root, 10);

  /* The AVL Tree after deletion of 10
          1
         /  \
        0    9
      /     /  \
     -1    5     11
         /  \
        2    6
  */

  printf("\nPreorder traversal after deletion of 10 \n");
  print_preOrder(root);

  return 0;

}