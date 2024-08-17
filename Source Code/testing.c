#include "dispTree.c"
// #include <bintree.h>
#include <stdio.h>
#include "RB-Tree.c"
void main(){
    // // node *root = create_node(48);
    // // disp_tree(root, " hi guys");
    // RBNode *root = NULL;
    // root = insertRB(root, 13);
    // root = insertRB(root, 4);
    // // // root->left->color = BLACK;
    // // // root->left = createNode(5);
    // // // root->right = createNode(4);
    // // // root->right->left = createNode(13);
    // // // root->right->right = createNode(15);
    // dispTree(root);
    // int arr[] = {8,18,5,15,17,25,40,80};
    int arr[] = {8, 18, 5,15, 17, 25, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    RBNode* root = NULL;
    for (int a = 0 ; a < size ; a++){
        root = insertRB(root, arr[a]);
    }
    dispTree(root);
}