//
// Created by hussamelemmawi on 09/03/17.
//

#include "binary-search-tree.h"
#include <stdio.h>
#include <stdlib.h>

BST *create(int rootValue) {
  BST *new_bst = malloc(sizeof(BST));
  new_bst->root = malloc(sizeof(Node));
  new_bst->root->left = NULL;
  new_bst->root->right = NULL;
  new_bst->root->value = rootValue;
  return new_bst;
}

void destroy(BST *bst) {
  destroy_node(bst->root);
}

void destroy_node(Node *node) {
  if (node == NULL) return;

  destroy_node(node->left);
  destroy_node(node->right);
  free(node);
}

int get_node_count(Node *node) {
  if (node == NULL) return 0;
  return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void preOrder(Node *node) {
  if (node != NULL) {
    printf("%d", node->value);
    preOrder(node->left);
    preOrder(node->right);
  }
}

void inOrder(Node *node) {
  if (node != NULL) {
    inOrder(node->left);
    printf("%d", node->value);
    inOrder(node->right);
  }
}

void postOrder(Node *node) {
  if (node != NULL) {
    postOrder(node->left);
    postOrder(node->right);
    printf("%d", node->value);
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

Node *find_max(Node *node) {
  if (node->right == NULL) return node;
  find_max(node->right);
}

int max(int a, int b) {
  return a >= b ? a : b;
}

int height_of(Node *node) {
  if (node == NULL) return 0;
  return 1 + max(height_of(node->left), height_of(node->right));
}

Node *create_node(Node *node, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert(Node *node, int value) {
  if (node->value > value) {
    if (node->left == NULL) {
      node->left = create_node(node, value);
    } else {
      insert(node->left, value);
    }
  } else if (node->value < value) {
    if (node->right == NULL) {
      node->right = create_node(node, value);
    } else {
      insert(node->right, value);
    }
  } else {
    // when node-value == value, return as there is nothing to do.
    return;
  }
}

Node *delete(Node *node, int value) {
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

  return node;
}

Node *get_successor(Node *node) {
  if (node->right != NULL)
    return find_min(node->right);
  else {
    Node *successor = NULL;
    Node *ancestor = node;

    while (ancestor != NULL) {
      if (ancestor->value < node->value) {
        successor = ancestor;
        ancestor = ancestor->left;
      } else
        ancestor = ancestor->right;
    }
    return successor;
  }
}