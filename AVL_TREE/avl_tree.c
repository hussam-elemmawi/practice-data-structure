//
// Created by hussamelemmawi on 13/03/17.
//

#include "avl_tree.h"

#include <stdio.h>
#include <stdlib.h>

AVL_TREE *create(int rootValue) {
  AVL_TREE *new_avltree = malloc(sizeof(AVL_TREE));
  new_avltree->root = malloc(sizeof(Node));
  new_avltree->root->left = NULL;
  new_avltree->root->right = NULL;
  new_avltree->root->value = rootValue;
  new_avltree->root->height = 0;
  return new_avltree;
}

void destroy(AVL_TREE *avltree) {
  destroy_node(avltree->root);
}

void destroy_node(Node *node) {
  if (node == NULL) return;

  destroy_node(node->left);
  destroy_node(node->right);
  free(node);
}

int print_preOrder(Node *node) {
  if (node != NULL) {
    printf("%d\t", node->value);
    print_preOrder(node->left);
    print_preOrder(node->right);
  }
}

int print_inOrder(Node *node) {
  if (node != NULL) {
    print_inOrder(node->left);
    printf("%d\t", node->value);
    print_inOrder(node->right);
  }
}

int print_postOrder(Node *node) {
  if (node != NULL) {
    print_postOrder(node->left);
    print_postOrder(node->right);
    printf("%d\t", node->value);
  }
}

Node *find(Node *node, int value) {
  if (node != NULL) {
    if (value > node->value) {
      find(node->right, value);
    } else if (value < node->value) {
      find(node->left, value);
    } else {
      return node;
    }
  } else
    return NULL;
}

Node *find_min(Node *node) {
  if (node->left == NULL) return node;
  find_min(node->left);
}

int max(int a, int b) {
  return a > b ? a : b;
}

int height_of(Node *node) {
  if (node == NULL) return 0;
  return node->height;
}

int calc_height(Node *node) {
  if (node == NULL) return 0;
  return 1 + max(height_of(node->left), height_of(node->right));
}

Node *create_node(int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->height = 1;
  return new_node;
}

int calcBalanceFactor(Node *node) {
  if (node == NULL)
    return 0;
  return height_of(node->left) - height_of(node->right);
}

Node *left_rotate(Node *x) {
  // Prepare nodes that gonna make the work
  Node *y = x->right;
  Node *T2 = y->left;

  // Rotate
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = calc_height(x);
  y->height = calc_height(y);

  // Return new root
  return y;
}

Node *right_rotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = calc_height(y);
  x->height = calc_height(x);

  // Return new root
  return x;
}

Node *insert(Node *node, int value) {
  // 1. perform normal BST insert

  if (node == NULL)
    return create_node(value);

  if (value < node->value) // go left
    node->left = insert(node->left, value);
  else if (value > node->value)
    node->right = insert(node->right, value);
  else return node;

  // 2. update height of this ancestor
  node->height = calc_height(node);

  // 3. get the balance of this ancestor node to check whether is unbalanced or not.
  int balanceFactor = calcBalanceFactor(node);

  // 4. If these unbalanced node, then will be 4 cases.

  // Left-heavy && not a Zigzag
  if (balanceFactor > 1 && value < node->left->value) {
    // TODO: right-rotate(node)
    return right_rotate(node);
  }
  // Left-heavy && a Zigzag
  if (balanceFactor > 1 && value > node->left->value) {
    // TODO: left-rotate(node->left)
    // TODO: right-rotate(node)
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }
  // Right-heavy && not a Zigzag
  if (balanceFactor < -1 && value > node->right->value) {
    // TODO: left-rotate(node)
    return left_rotate(node);
  }
  // Right-heavy && a Zigzag
  if (balanceFactor < -1 && value < node->right->value) {
    // TODO: right-rotate(node->right)
    // TODO: left-rotate(node)
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }

  return node;
}

Node *delete(Node *node, int value) {
  // 1. Perform normal BST delete
  if (node == NULL) return node;

  if (value < node->value) {
    node->left = delete(node->left, value);
  } else if (value > node->value) {
    node->right = delete(node->right, value);
  } else {  // found value

    if (node->left == NULL && node->right == NULL) {
      free(node);
      node = NULL;
    } else if (node->left == NULL) {
      Node *tmp = node;
      node = node->right;
      free(tmp);
    } else if (node->right == NULL) {
      Node *tmp = node;
      node = node->left;
      free(tmp);
    } else {
      // 2 children - get min node of right subtree
      int right_min = find_min(node->right)->value;
      node->value = right_min;
      node->right = delete(node->right, right_min);
    }
  }

  // 2. update height of this ancestor
  node->height = calc_height(node);

  // 3. get the balance of this ancestor node to check whether is unbalanced or not.
  int balanceFactor = calcBalanceFactor(node);

  // 4. If these unbalanced node, then will be 4 cases.

  // Left-heavy && not a Zigzag
  if (balanceFactor > 1 && calcBalanceFactor(node->left) >= 0) {
    return right_rotate(node);
  }
  // Left-heavy && a Zigzag
  if (balanceFactor > 1 && calcBalanceFactor(node->left) < 0) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }
  // Right-heavy && not a Zigzag
  if (balanceFactor < -1 && calcBalanceFactor(node->right) < 0) {
    return left_rotate(node);
  }
  // Right-heavy && a Zigzag
  if (balanceFactor < -1 && calcBalanceFactor(node->right) >= 0) {
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }


  return node;
}
