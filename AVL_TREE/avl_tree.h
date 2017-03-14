//
// Created by hussamelemmawi on 13/03/17.
//

#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
    int height;
} Node;

typedef struct AVL_tree {
    Node *root;
} AVL_TREE;

AVL_TREE *create(int rootValue);

void destroy(AVL_TREE *avltree);

void destroy_node(Node *node);

int print_preOrder(Node *node);

int print_inOrder(Node *node);

int print_postOrder(Node *node);

Node *find(Node *node, int value);

Node *find_min(Node *node);

int height_of(Node *node);

Node *left_rotate(Node *x);

Node *right_rotate(Node *x);

Node *insert(Node *node, int value);

Node *delete(Node *node, int value);

#endif //AVL_TREE_AVL_TREE_H
