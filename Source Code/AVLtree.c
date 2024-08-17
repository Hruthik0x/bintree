#include <stdio.h>
#include "bintree.h"
#include "dispTree.c"
#include <stdlib.h>
#include <stdarg.h>
#include "Rotations.c"
//Gives the inorderPredecessor of the given Node
//assumes that LebSub tree is not NULL, if its NULL, returns NULL
//delinks the inorderPredecessor from its parent
//Add the path of inorderPredecessor to given path
Node* inOrderPredecessor(Node **path, int *pathLength ,Node *nodeToBeDeleted){

    if (nodeToBeDeleted == NULL)
        return NULL;

    //index of nodeToBeDeleted in path

    int nodeToBeDeletedIndex = (*pathLength)-1;

    //replacementNode is the inorderPredecessor of the nodeToBeDeleted
    Node *replacementNode = nodeToBeDeleted->left;
    if ( replacementNode == NULL )
        return replacementNode;

    Node *parent = NULL;

    while(replacementNode->right!=NULL){
        parent = replacementNode;              //finding Parent Node;
        (*pathLength)++;
        path = realloc(path, SIZE_ADDRESS*(*pathLength));
        path[(*pathLength)-1] = replacementNode;
        replacementNode = replacementNode->right;
    }


    // if (replacementNode != nodeToBeDeleted->left)
    //     (*pathLength)--;

    //replacing nodeToBeDeleted with replacementNode in the path
    path[nodeToBeDeletedIndex] = replacementNode;

    if (parent != NULL)
        parent->right = NULL;           //delinking inorder predecessor from its parentnode
    return replacementNode;
}

//Displays an array
//Assumes the 1st element (Element at index 0) as the size of the array
//All elements except the first element (Element at index 0) are actual values
//Example arr = {3,84,26,94} First element (arr[0]) is 3, so there are 3 values stored in it 84,26,94
void dispArr(int *arr){  
    if (arr == NULL)
        return;
    int size = arr[0];
    for (int a = 1 ; a <= size ; a++){
        printf("%d ",arr[a]);
    }
    printf("\n");
}

int findNodeHeight(Node* node){
    if (node == NULL)
        return 0;
    else {
        int lHeight = maxDepth(node->left);
        int rHeight = maxDepth(node->right);
        return max(lHeight, rHeight)+1;
    }
}

//when subTreeHeight(root->left) is called, it calculates the height of left subtree of the root
int subTreeHeight(Node *root){
    if (root == NULL)
        return 0;
    return findNodeHeight(root)+1;
}

Node *insertAVL(Node *root, int num){

    Node *newNode = createNode(num);
    Node *child = NULL;
    Node *parent = NULL;
    Node *grandParent = NULL;
    Node *greatGrandParent = NULL;

    if (root == NULL)
        return newNode;

    Node *node = root;
    Node **path = malloc(SIZE_ADDRESS);
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

    for (int a = pathLength-3; a>=0 ; a-- ){

        child = path[a+2];
        parent = path[a+1];
        grandParent = path[a];

        Node* newGrandParent = NULL;
        int balanceFactor = subTreeHeight(grandParent->left) - subTreeHeight(grandParent->right);
        if (balanceFactor == 2){
            if (parent->left == child)
                newGrandParent = LLRotation(grandParent, parent, child);
            else
                newGrandParent = LRRotation(grandParent, parent, child);
        }
        else if (balanceFactor == -2){
            if (parent->right == child)
                newGrandParent = RRRotation(grandParent, parent, child);
            else
                newGrandParent = RLRotation(grandParent, parent, child);
        }
        if (balanceFactor == 2 || balanceFactor == -2){
            if (a >= 1){
                greatGrandParent = path[a-1];
                if (greatGrandParent->left == grandParent)
                    greatGrandParent->left = newGrandParent;
                else 
                    greatGrandParent->right = newGrandParent;
            }
            else 
                root = newGrandParent;
                
            free(path);
            return root;
        }
    }
    free(path);
    return root;

}

Node *deleteAVL(Node *root, int num){

    Node *node = root;
    int found = 0;

    Node **path = malloc(SIZE_ADDRESS);
    int pathLength = 0;

    while(node!=NULL){

        pathLength++;
        path = realloc(path, pathLength*SIZE_ADDRESS);
        path[pathLength-1] = node;


        if (node->num < num)
            node = node->right;
        else if (node->num > num)
            node = node->left;
        else {
            found = 1;
            break;
        }
    }

    if (found == 0){
        free(path);
        return root;
    }

    else{
        Node *nodeToBeDeleted = path[pathLength-1];
        Node *parent = NULL;

        if (nodeToBeDeleted != root)
            parent = path[pathLength-2];

        int height = findNodeHeight(nodeToBeDeleted);

        if (height == 0){   //Leaf node
            pathLength--;       //Excluding nodeToBeDeleted in the path
            if (parent != NULL){   //nodeToBeDeleted is not the root
                if (parent->left == nodeToBeDeleted)
                    parent->left = NULL;
                else{
                    parent->right = NULL;
                }
            }
            else {               //nodeToBeDeleted is root and is the only node in the tree
                free(path);
                free(nodeToBeDeleted);
                return NULL;
            }
        }
        else{
            Node *replacementNode;

            //nodeToBeDeleted has only one child
            if (nodeToBeDeleted->right == NULL){
                replacementNode = nodeToBeDeleted->left;
                pathLength--;   //Excluding nodeToBeDeleted from the path
            }
            else if (nodeToBeDeleted->left == NULL){
                replacementNode = nodeToBeDeleted->right;
                pathLength--;   //Excluding nodeToBeDeleted from the path
            }

            //nodeToBeDeleted has 2 children
            else{
                //Since nodeToBeDeleted has 2 children, inOrderPredecessor of nodeToBeDeleted cannot be NULL
                replacementNode = inOrderPredecessor(path, &pathLength, nodeToBeDeleted);
                replacementNode->right = nodeToBeDeleted->right;
                if (replacementNode != nodeToBeDeleted->left){
                    replacementNode->left = nodeToBeDeleted->left;
                }
            }


            if (parent != NULL){    //nodeToBeDeleeted is not the root
                if (parent->left == nodeToBeDeleted)
                    parent->left = replacementNode;
                else 
                    parent->right = replacementNode;
            }
            else
                root = replacementNode;

            
        }
        free(nodeToBeDeleted);
    }

    // if (num != 15)
    Node *child = NULL;
    Node *parent = NULL;
    Node *grandParent = NULL;
    Node *newGrandParent = NULL;


    for (int a = pathLength-1; a >= 0 ; a--){
        grandParent = path[a];
        int balanceFactor = subTreeHeight(grandParent->left) - subTreeHeight(grandParent->right);

        if (balanceFactor == 2){
            parent = grandParent->left;

            if (parent->left != NULL){
                child = parent->left;
                newGrandParent = LLRotation(grandParent, parent, child);
            }
            else{
                child = parent->right;
                newGrandParent = LRRotation(grandParent, parent, child);
            }
        }
        else if (balanceFactor == -2){
            parent = grandParent->right;

            if (parent->right !=NULL){
                child = parent->right;
                newGrandParent = RRRotation(grandParent, parent, child);
            }
            else{
                child = parent->left;
                newGrandParent = RLRotation(grandParent, parent, child);
            }
        }
        if (balanceFactor == 2 || balanceFactor == -2){
            if (grandParent == root)
                root = newGrandParent;
            else {
                Node* greatGrandParent = path[a-1];
                if (greatGrandParent->left == grandParent)
                    greatGrandParent->left = newGrandParent;
                else
                    greatGrandParent->right = newGrandParent;
            }

            free(path);
            return root;
        }
    } 
    return root;
}


void main(){

// Test cases standard :
    // int arr[] = {3,1,2}; //LR root
    // int arr[] = {3,1,2,-2,-1}; //LR noroot
    // int arr[] = {3,2,1}; // LL root
    // int arr[] = {3,2,1,0,-1}; // LL noroot
    // int arr[] = {1,3,2}; //RL root
    // int arr[] = {1,2,3,5,4}; //RL noroot
    // int arr[] = {1,2,3};//RR root
    // int arr[] = {1,2,3,4,5}; //RR noroot

//Test cases non-standard :
    // int arr[] = {63, 9, 19, 27, 18, 108, 99, 81};
    // int arr[] = {15 , 18 , 12 , 8 , 54 , 5 , 14 , 13 , 9 , 60};
    // int arr[] = {6,9,15,12,7,4,1,0,25,3,19};
    // int arr[] = {21,26,30,9,4,14,28,18,15,10,2,3,5};
    // Node *root = NULL;
    // int size = sizeof(arr)/sizeof(int);
    // for (int a = 0 ; a < size ; a++)
    //     root = insertAVL(root,arr[a]);

    // Node *root = createNode(13);
    // root->left = createNode(5);
    // root->left->left = createNode(2);
    // root->left->right = createNode(8);
    // root->left->left->left = createNode(1);
    // root->left->right->left = createNode(6);
    // root->left->right->right = createNode(11);

    // root->right = createNode(25);
    // root->right->left = createNode(15);
    // root->right->left->right = createNode(17);
    // root->right->right = createNode(29);
    // root->right->right->right = createNode(40);
    // root->right->right->left = createNode(27);

    // printf("%d",findNodeHeight(root->left));
    // disp_tree(root);

    // int arr[] = {1,2,11,17,5,8,13,6,15};
    // int arr[] = {1,2,11,17,5,8,13,6,15};

    // Node *root = createNode(9);
    // root->left = createNode(8);
    // root->left->left = createNode(7);
    // root->right = createNode(15);
    // root->right->left = createNode(13);
    // root->right->right = createNode(20);
    // root->right->left->left = createNode(10);

    Node *root = createNode(15);
    root->left = createNode(11);
    root->left->left = createNode(6);
    root->left->right = createNode(12);
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(8);
    root->left->right->right = createNode(13);

    root->right = createNode(18);
    root->right->left = createNode(17);
    root->right->left->left = createNode(16);
    root->right->right = createNode(54);
    root->right->right->right = createNode(65);
    // dispTree(root);

    // root = deleteAVL(root, 8);
    // dispTree(root);
    // // int arr[] = {8,6,11,15,17};
    int arr[] = {8, 6, 11, 15, 17};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int a = 0 ; a < size ; a++)
        root = deleteAVL(root, arr[a]);
    dispTree(root);

}