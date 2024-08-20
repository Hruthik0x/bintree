#ifndef BINTREELIBV1
#define BINTREELIBV1

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node *create_node(int data);
void disp_tree(node *root,...);
#endif