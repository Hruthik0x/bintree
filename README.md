# bintree
A C library to make the visualization of binary trees in C easier
Please, go through all of the points


1) Run the Setup.out via the terminal for the installation

2) Use the struct mentioned in bintree.h to create nodes (else you would run into errors)
   which is :

![image](https://github.com/Hruthik0x/bintree/assets/69683617/548f4986-b44d-41bc-a1d9-a6a93267fae5)


3) Since the node is already declared/defined for you, no need to create a separate struct for the binary tree.

4) Also create_node function is already declared/defined which would create the node and return the node address for you.

5) If you want to use custom names for members, structs and functions, you can use the macro (#define)
   
   ![image](https://github.com/Hruthik0x/bintree/assets/69683617/86509516-4046-4868-af84-3b27455d6b2a)

	
6) Use disp_tree(root_address) to visualize the binary tree on your browser

   Code :
   
![image](https://github.com/Hruthik0x/bintree/assets/69683617/f97ecf55-de99-492e-95ff-e9efd896d733)

   Output :

   ![image](https://github.com/Hruthik0x/bintree/assets/69683617/63cc8cd2-5f1f-468e-a470-b31bec9a2570)

			or
   
   Use disp_tree(root_adress, custom_string) to visualize the binary tree with the custom_string on the top left, 
   so that you can keep track of the instances where you used the disp_tree function
   
9) To compile the code use this :
	gcc myprogram.c -lbintree
	
10) To remove the library run the Uninstall.out via the terminal
	
	

