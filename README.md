# bintree

**Note** : Specific to Linux OS

A C library to make the visualization of binary trees in C easier

Please, go through all of the points mentioned below

Repo link : https://github.com/Hruthik0x/bintree

To know your architecture use the following command in the terminal : 

	uname -m

| Output   | Architecture    |
| -------- | --------------- |
| x86_64   | x86 (64 bit)    |
| i686     | x86 (32 bit)    |
| aarch64  | ARM (64 bit)    |
| armv7l   | ARM (32 bit)    |

     
Download the repo, unzip/extract the files and open the terminal in the directory that corresponds to your architecture.

For example, if your architecture is x86 (64 bit) then open the terminal in /Bintree/x86 (64bit) folder and follow the below steps.

1) Run the setup via the terminal for the installation
   
    ```sh
    chmod a+x setup
    ./setup
    ```

2) After the setup, use this, to include the library
    ```
    #include <bintree.h>
    ```

4) The struct node is a **pre-defined data structure within this library.**
   It has already been declared, and **there's no need to declare it again explicitly.**
   Users can directly use it in their code without any **additional declarations**.
    ```C
    \\This struct is already declared in <bintree.h>, so there's no need to declare it again explicitly
    typedef struct node{
        int data;
        struct node *right;
        struct node *left;
     }node;
     ```

5) Also create_node function is already declared/defined which would create the node and return the node address for you.

6) If you want to use custom names for members, structs and functions, you can use the macro (#define)

   ```C
   #define my_node node
   #define left_child left
   #define right_child right
   #define number data
   #define my_createnode create_node
   ```

7) Use disp_tree(root_address) to visualize the binary tree on your browser

   Example :

    ```C
    node *root = NULL;
    int list_1[11] = {33,42,22,70,20,28,1,39,84,26,-30};
    for (int a = 0 ; a < 11 ; a++)
        root = insert_bst(root,list_1[a]);    \\insert_bst function (Inserts elements in binary search tree) is not included in the library
    disp_tree(root);
    ```

   Output :

    ![](https://github.com/Hruthik0x/bintree/assets/69683617/27bf7a40-4b03-4b72-bc51-d19e6014078b)


**OR**
   
8) Use disp_tree(root_adress, custom_string) to visualize the binary tree with the custom_string on top of the binary tree, 
   so that you can keep track of the instances where you used the disp_tree function

   Example : 
   
    ```C
    node *root = NULL;
    int list_1[11] = {33,42,22,70,20,28,1,39,84,26,-30};
    for (int a = 0 ; a < 11 ; a++)
        root = insert_bst(root,list_1[a]);	\\insert_bst function (Inserts elements in binary search tree) is not included in the library
    disp_tree(root,"Before inserting from list_2");
    int list_2[4] = {21,30,40,41};
    for (int a = 0 ; a < 4 ; a++)
        root = insert_bst(root, list_2[a]);	\\insert_bst function (Inserts elements in binary search tree) is not included in the library
    disp_tree(root,"After inserting from list_2");
    ```

   Output :

   ![](https://github.com/Hruthik0x/bintree/assets/69683617/d7fead00-fc57-47d3-870f-b6a49da70dc9)

   ![](https://github.com/Hruthik0x/bintree/assets/69683617/8d95f56a-b330-4ab2-bf87-e2471a9321a5)


9) To compile the code use this :
   
   ```
   gcc myprogram.c -lbintree
   ```

10) To remove the library run the Uninstall.out via the terminal

    ```
    chmod a+x uninstall
    ./uninstall
    ```
	
	

