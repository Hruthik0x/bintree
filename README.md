# bintree
A C library to make the visualization of binary trees in C easier
Please, go through all of the points


1) Run the Setup.out via the terminal for the installation
   
```bash
chmod a+x Setup.out
./Setup.out
```

2) Use the struct mentioned in bintree.h to create nodes (else you would run into errors)
   which is :

```C
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;
```

3) Since the node is already declared/defined for you, no need to create a separate struct for the binary tree.

4) Also create_node function is already declared/defined which would create the node and return the node address for you.

5) If you want to use custom names for members, structs and functions, you can use the macro (#define)

   ```C
   #define my_node node
   #define left_child child
   #define right_child child
   #define number data
   #define my_createnode create_node
   ```
   
   ![image](https://github.com/Hruthik0x/bintree/assets/69683617/86509516-4046-4868-af84-3b27455d6b2a)

	
6) Use disp_tree(root_address) to visualize the binary tree on your browser

   Example :

```C
    node *root = NULL;
    int list_1[11] = {33,42,22,70,20,28,1,39,84,26,-30};
    for (int a = 0 ; a < 11 ; a++)
        root = insert_bst(root,list_1[a]);
    disp_tree(root);
```

   Output :
   
![image](https://github.com/Hruthik0x/bintree/assets/69683617/66681ee4-1042-45ce-9f41-1366bed46eeb)

**OR**
   
7) Use disp_tree(root_adress, custom_string) to visualize the binary tree with the custom_string on top of the binary tree, 
   so that you can keep track of the instances where you used the disp_tree function

   Example : 
   
```C
    node *root = NULL;
    int list_1[11] = {33,42,22,70,20,28,1,39,84,26,-30};
    for (int a = 0 ; a < 11 ; a++)
        root = insert_bst(root,list_1[a]);
    disp_tree(root,"Before inserting from list_2");
    int list_2[4] = {21,30,40,41};
    for (int a = 0 ; a < 4 ; a++)
        root = insert_bst(root, list_2[a]);
    disp_tree(root,"After inserting from list_2");
```

   Output :
   
   ![image](https://github.com/Hruthik0x/bintree/assets/69683617/9969e1b8-d4a5-4ca0-90c4-32c68788e14c)
   
   ![image](https://github.com/Hruthik0x/bintree/assets/69683617/ce1811a3-24e7-4836-a2d4-92ae1380133c)

8) To compile the code use this :
   
   ```
	gcc myprogram.c -lbintree
   ```

9) To remove the library run the Uninstall.out via the terminal

    ```
    chmod a+x Uninstall.out
    ./Uninstall.out
    ```
	
	

