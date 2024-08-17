#include "bintree.h"

Node* LLRotation(Node *grandParent, Node *parent, Node* child){

    grandParent->left = parent->right;
    parent->right = grandParent;

    return parent;
}

Node* LRRotation(Node *grandParent, Node *parent, Node* child){

    parent->right = child->left;
    grandParent->left = child->right;

    child->right = grandParent;
    child->left = parent;

    return child;
}

Node* RRRotation(Node *grandParent, Node *parent, Node* child){

    grandParent->right = parent->left;
    parent->left = grandParent;

    return parent;
}

Node* RLRotation(Node *grandParent, Node *parent, Node* child){

    grandParent->right = child->left;
    parent->left = child->right;

    child->left = grandParent;
    child->right = parent;

    return child;
}