//
// Created by hussamelemmawi on 09/03/17.
//

#ifndef BST_BINARY_SEARCH_TREE_H
#define BST_BINARY_SEARCH_TREE_H

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct binary_search_tree {
    Node *root;
} BST;

BST *create(int rootValue);

void destroy(BST *bst);

void destroy_node(Node *node);

int get_node_count(Node *node);

int print_preOrder(Node *node);

int print_inOrder(Node *node);

int print_postOrder(Node *node);

Node *find(Node *node, int value);

Node *find_min(Node *node);

Node *find_max(Node *node);

int height_of(Node *node);

void insert(Node *node, int value);

Node *delete(Node *node, int value);

Node *get_successor(Node *node);

#endif //BST_BINARY_SEARCH_TREE_H
