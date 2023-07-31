# bintree
A C library to make the visualization of binary trees in C easier
Please, go through all of the points


1) Run the Setup.out via the terminal for the installation

2) Use the struct mentioned in bintree.h to create nodes (else you would run into errors)
   which is :

   typedef struct node{
       int data;
       struct node *right;
       struct node *left;
   }node;


3) Since the node is already declared/defined for you, no need to create a separate struct for the binary tree.

4) Also create_node function is already declared/defined which would create the node and return the node address for you.

5) If you want to use custom names for members, structs and functions, you can use the macro (#define)
   Example :
	#include <bintree.h>
	#define myNode node
	#define leftchild left
	#define rightchild right
	#define number data
	#define my_createNode create_node
	
6) Use disp_tree(root_address) to visualize the binary tree on your browser 
			or
   Use disp_tree(root_adress, custom_string) to visualize the binary tree with the custom_string on the top left, 
   so that you can keep track of the instances where you used the disp_tree function
   
7) To compile the code use this :
	gcc myprogram.c -lbintree
	
8) To remove the library run the Uninstall.out via the terminal
	
	

