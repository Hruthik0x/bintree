#include <stdio.h>
#include "bintree.h"
#include "Rotations.c"

RBNode* insertRB(RBNode *root, int num){
    RBNode *newNode = createRBNode(num);
    if (root == NULL){
        root = newNode;
        root->color = BLACK;
        return root;
    }
    
    //Inserting into BST..
    RBNode *node = root;
    RBNode **path = malloc(SIZE_ADDRESS);
    int pathLength = 1;

    while(1){
        path[pathLength-1] = node;
        pathLength++;
        path = realloc(path, pathLength*SIZE_ADDRESS);

        if (num >= node->num){
            if (node->right != NULL)
                node = node->right;
            else{
                node->right = newNode;
                break;
            }
        }
        else {
            if (node->left != NULL)
                node = node->left;
            else{
                node->left = newNode;
                break;
            }
        }
    }


    path[pathLength-1] = newNode;
    for (int a = pathLength-1 ; a>= 1 ; a--){

        RBNode *child = path[a];
        RBNode *parent = path[a-1];

        if (parent->color == RED){
            RBNode *grandParent = path[a-2];
            RBNode *parentsSibling = NULL;
            RBNode *newGrandParent = NULL;
            if (grandParent->left == parent)
                parentsSibling = grandParent->right;
            else 
                parentsSibling = grandParent->left;

            if (parentsSibling == NULL || parentsSibling->color == BLACK){
                if (grandParent->left == parent){
                    if (parent->left == child)
                        newGrandParent  = (RBNode *)LLRotation((Node *)grandParent, (Node *)parent, (Node *)child);
                    else
                        newGrandParent = (RBNode *)LRRotation((Node *)grandParent, (Node *)parent, (Node *)child);
                }
                else{
                    if (parent->right == child)
                        newGrandParent  = (RBNode *)RRRotation((Node *)grandParent, (Node *)parent, (Node *)child);
                    else 
                        newGrandParent = (RBNode *)RLRotation((Node *)grandParent, (Node *)parent, (Node *)child);  
                }
            
                if (grandParent == root)
                    root = newGrandParent;
                else{
                    newGrandParent->color = BLACK;
                    grandParent->color = RED;
                    RBNode* greatGrandParent = path[a-3];
                    if (greatGrandParent->left == grandParent)
                        greatGrandParent->left = newGrandParent;
                    else 
                        greatGrandParent->right = newGrandParent;
                }
                free(path);
                return root;
            }
            else{
                parentsSibling->color = BLACK;
                parent->color = BLACK;
                if (grandParent == root){
                    free(path);
                    return root;
                }
                else{
                    grandParent->color = RED;
                    a--;
                } 
            }
        }
    }
    free(path);
    return root;
}
