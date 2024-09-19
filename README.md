### Note : The repo has been moved to github.com/hruthik0x/disptree , sorry for the invonvinience. The following is a copy of README.md, you can take a look.

# Disptree
Note : Tested on Linux, gcc and g++

Repo link : https://github.com/Hruthik0x/disptree/

How to use ? 

**Note** : 
- RBNode, Node, createNode, dispTree are provided by dispTree lib.
- dispTree accepts both Node* and RBNode*

```C++
Node* root = createNode(1);
root->left = createNode(2);
root->right = createNode(3);
root->left->left = createNode(4);
root->left->right = createNode(5);
root->right->left = createNode(6);
root->right->right = createNode(7);

// Call this function to display the tree in browser
dispTree(root);
```

Output : 

```C++
RBNode* root = createRBNode(10);
root->color = BLACK; // Root must be black

root->left = createRBNode(5);
root->right = createRBNode(15);

root->left->left = createRBNode(3);
root->left->left->color = BLACK;

root->left->right = createRBNode(7);
root->left->right->color = BLACK;

root->right->left = createRBNode(13);
root->right->left->color = BLACK;

root->right->right = createRBNode(17);
root->right->right->color = BLACK;

// Call this function to display the tree in browser
dispTree(root);
```

Output : 


## Installation
There are two ways to install library, if you do not know what to choose, simply follow "Single header file" installation.


**Note :** 
If you install disptree using the "Compile lib" option, you have to use ` -ldisptree`, every time you compile, e.g., `gcc test.c -ldisptree`.

Whereas if you follow the "Single header file" option, you can compile it *without* using ` -ldisptree`, i.e., `gcc test.c`.

### Single header file 
 
```
git clone https://github.com/Hruthik0x/disptree/
sudo cp disptree/single-header/disptree.h /usr/local/include
```

Now you can use disptree, by using `#include <disptree.h>` 

### Compile lib
Choose either static or dynamic.

Please read the note mentioned in Installation section.

```
git clone https://github.com/Hruthik0x/disptree/
sudo cp disptree/src/disptree.h /usr/local/include
```

For static : 
```
gcc -c disptree.c -o disptree.o
ar rcs libdisptree.a disptree.o
sudo cp libdisptree.a /usr/local/lib
sudo ldconfig
```

For dynamic : 
```
gcc -fPIC -c disptree.c -o disptree.o
gcc -shared -o libdisptree.so disptree.o
sudo cp libdisptree.so /usr/local/lib/
sudo ldconfig
```
