#ifndef BINTREELIBV2
#define BINTREELIBV2
#include <stdlib.h>
#include "js-code-1.h"
#include "js-code-2.h"

typedef struct Node{
    int num;
    struct Node *left;
    struct Node *right;
}Node;

typedef enum Color {RED, BLACK} Color;

typedef struct RBNode{
    int num;
    struct RBNode *left;
    struct RBNode *right;
    Color color;
}RBNode;

const size_t SIZE_NODE = sizeof(Node);
const size_t SIZE_RBNODE = sizeof(RBNode);
const size_t SIZE_ADDRESS = sizeof(void *);

Node *createNode(int num){
    Node* node = malloc(SIZE_NODE);
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    return node;
}

RBNode* createRBNode(int num){
    RBNode* newNode = malloc(SIZE_RBNODE);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->num = num;
    newNode->color = RED;
    return newNode;
}

int max(int a, int b){
    if (a > b)
        return a;
    else 
        return b;
}
#endif