#include <stdio.h>
#include "bintree.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

#define dispTree(x) _Generic((x),\
    Node* : dispNodeTree,\
    RBNode* : dispRBTree \
    )(x)

//For the js file, (canvas).. Refer to script.js in
#define OUTER_RAD 25                    //Circle outer radius
#define INNER_RAD 21                    //Circle inner radius
#define LINE_WIDTH 4                    //Node connecting lines width
#define DEFAULT_TREE_COLOR "#007bff"    
#define BLACK_COLOR "#000000"
#define RED_COLOR "#ff0000"
#define GREY_COLOR "#404040"
#define DEFAULT_BG_COLOR "#161617"
 
static const int Y_DIS = 80;                   //Vertical distance between parent and child node
static const int X_DIS = 60;                   //Horizontal distance between two sibling nodes at same level

//Assuming that screen is 1920*1080
static const int Y_MAX_ASSUMED = 940;          //Assumption that browsers max height 
const int X_MAX_ASSUMED = 1880;         //Assumption that browsers max width

static int callTimes = 0;                      //No.of times dispTree is called

static const char* folderName = "bintree files";

static int inorder(void* root, FILE* lineFile, FILE* circleFile,int* xLevel, int yLevel, int* yExtreme, int isRB){

    if (root == NULL)
        return 0;

    int childXCor, retVal;

    Node *rootNode = NULL;
    RBNode *rootRBNode = NULL;
    void *address;

    if (isRB){
        rootRBNode = (RBNode*)root;
        if ((*xLevel) > 0)      //Inorder Left-Root-Right
            retVal = inorder((void*)(rootRBNode->left), lineFile, circleFile, xLevel,yLevel+1, yExtreme, isRB);
        else                   //Reverse Inorder Right-Root-Left   
            retVal = inorder((void*)(rootRBNode->right), lineFile, circleFile, xLevel,yLevel+1,yExtreme, isRB);
    }
    else {
        rootNode = (Node*)root;
        if ((*xLevel) > 0)      //Inorder Left-Root-Right
            retVal = inorder((void*)(rootNode->left), lineFile, circleFile, xLevel,yLevel+1, yExtreme, isRB);
        else                   //Reverse Inorder Right-Root-Left   
            retVal = inorder((void*)(rootNode->right), lineFile, circleFile, xLevel,yLevel+1,yExtreme, isRB);
    }

    if (retVal != 0)        //if retval is zero, it means it encountered NULL child (refer inorder 1st line..)
        fprintf(lineFile, "drawLine(%d, %d, %d, %d);\n",(*xLevel)*X_DIS, yLevel*Y_DIS, (retVal)*X_DIS, (yLevel+1)*Y_DIS);
    
    if (isRB){
        if (rootRBNode->color == RED)
            fprintf(circleFile, "drawNode(%d, %d, %d, \"%s\");\n",rootRBNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS, RED_COLOR);
        else
            fprintf(circleFile, "drawNode(%d, %d, %d, \"%s\");\n",rootRBNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS, BLACK_COLOR);
    }
    else 
        fprintf(circleFile, "drawNode(%d, %d, %d, DEFAULT_TREE_COLOR);\n",rootNode->num, (*xLevel)*X_DIS, (yLevel)*Y_DIS);
    
    childXCor = *xLevel;

    if ((*xLevel) < 0)          //for left subtree, shifting away from 0, towards -ve  (refer dispTree)
        (*xLevel) = *xLevel-1;  
    else                        //for right subtree, shifting away from 0, towards +ve  (refer dispTree)
        (*xLevel) = *xLevel+1;

    if (*yExtreme < yLevel)     //yExtreme has the height of the tree..
        *yExtreme = yLevel;

    if (isRB){
        if (*xLevel > 0)       // Inorder Left-Root-Right
            retVal = inorder((void*)(rootRBNode->right), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
        else                   // Reverse Inorder Right-Root-Left  
            retVal = inorder((void *)(rootRBNode->left), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
    }
    else{
        if (*xLevel > 0)       // Inorder Left-Root-Right
            retVal = inorder((void*)(rootNode->right), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);
        else                   // Reverse Inorder Right-Root-Left  
            retVal = inorder((void*)(rootNode->left), lineFile, circleFile, xLevel, yLevel+1, yExtreme, isRB);        
    }

    if (retVal !=0 )
        //Using childXCor here as the xLevel is changed in if and else....
        fprintf(lineFile, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, (yLevel)*Y_DIS, (retVal)*X_DIS, (yLevel+1)*Y_DIS);

    //returns the X coordinate of the current node
    return childXCor;
}


static void dispTreeMain(void *root, int isRB){

    struct stat st;
    if (stat(folderName, &st) == -1) {
        if (mkdir(folderName, 0755) != 0){
            printf("Failed to create folder '%s'.\n", folderName);
            return;
        }
    }

    callTimes++;        //No.of times function called is increased..
    if (root == NULL)
        return;

    char buffer[1024];
    char fileName[50];  //Contains the filename..

    sprintf(fileName,"%s/script-%d.js",folderName, callTimes);
    FILE *jsFile1= fopen(fileName, "wb"); 

    if (jsFile1==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }

    fwrite(jsCode1, 1, jsCode1Len,jsFile1);     //Writing stuff from jsCode-1.js (which is in hex inside js-code-1.h) into jsCode1 (script-%d.js)
    fclose(jsFile1);

    jsFile1 = fopen(fileName, "a");             //Reopening it to add these.. (refer to script.js in ..)
    fprintf(jsFile1, "const OUTER_RAD = %d;\n", OUTER_RAD);
    fprintf(jsFile1, "const INNER_RAD = %d;\n", INNER_RAD);
    fprintf(jsFile1, "const LINE_WIDTH = %d;\n", LINE_WIDTH);
    fprintf(jsFile1, "const DEFAULT_TREE_COLOR = \"%s\";\n", DEFAULT_TREE_COLOR);

    if (isRB == 1){
        fprintf(jsFile1, "const LINE_COLOR = \"%s\";\n", DEFAULT_BG_COLOR);
        fprintf(jsFile1, "const BG_COLOR = \"%s\";\n", GREY_COLOR);
    }
    else{ 
        fprintf(jsFile1, "const BG_COLOR = \"%s\";\n", DEFAULT_BG_COLOR);
        fprintf(jsFile1, "const LINE_COLOR = \"%s\";\n", DEFAULT_TREE_COLOR);
    }

    FILE *jsFile2 = fopen("jsFile2.js", "wb");
    if (jsFile2==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }
    fwrite(jsCode2, 1, jsCode2Len,jsFile2);     //Writing stuff from jsCode-2.js (which is in hex inside js-code-2.h) into jsCode2
    fclose(jsFile2);    
    
    //Reopening it, to write the coordinates of lines..
    jsFile2 = fopen("jsFile2.js", "a");         

    sprintf(fileName,"circles-%d.txt",callTimes);   
    FILE *circleFile = fopen(fileName,"w");      //creating circelFile to write the circle coordinates in this file

    int leftXExtreme, leftYExtreme, rightXExtreme, rightYExtreme, childXCor;
    leftXExtreme = -1;  //xLevel for left subtree
    rightXExtreme = 1;  //xLevel for right subtree
    leftYExtreme = rightYExtreme = 0;   //initial heightd of bothe left and right subtrees are 0

    void *address ;
    if (isRB == 1)
        address = (void *)(((RBNode *)root)->left);
    else 
        address = (void *)(((Node *)root)->left);

    childXCor = inorder(address, jsFile2, circleFile,&leftXExtreme, 1, &leftYExtreme, isRB);       //xCor of the left child

    if (childXCor!=0)
        fprintf(jsFile2, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, Y_DIS, 0, 0);             //Connecting root and left child
    
    if (isRB == 1)
        address = (void *)(((RBNode *)root)->right);
    else 
        address = (void *)(((Node *)root)->right);

    childXCor = inorder(address, jsFile2, circleFile, &rightXExtreme,1, &rightYExtreme, isRB);    //xcor of the right child
    if (childXCor!=0)
        fprintf(jsFile2, "drawLine(%d, %d, %d, %d);\n",(childXCor)*X_DIS, Y_DIS, 0, 0);             //Connecting root and right child

    fclose(circleFile);
    circleFile = fopen(fileName,"r");

    int num;
    if (isRB == 1)
        num = ((RBNode *)root)->num;
    else 
        num = ((Node *)root)->num;

    if (isRB == 1){
        if (((RBNode *)root)->color == RED)
            fprintf(jsFile2, "drawNode(%d, %d, %d, \"%s\");\n",num, 0,0, RED_COLOR);
        else 
            fprintf(jsFile2, "drawNode(%d, %d, %d, \"%s\");\n",num, 0,0, BLACK_COLOR);
    }
    else 
        fprintf(jsFile2, "drawNode(%d, %d, %d, DEFAULT_TREE_COLOR);\n",num, 0,0);

    while (fgets(buffer, sizeof(buffer), circleFile) != NULL)      //Writing all the circle coordinates from circlefile into js file
        fputs(buffer, jsFile2);

    fclose(circleFile);
    remove(fileName);           //deleting circleFile
    fclose(jsFile2);           

    int treeHeight = max(leftYExtreme, rightYExtreme);          //Height = max(rightSubtree height, leftsubtree hright)        
    int treeWidth = max(-1*leftXExtreme, rightXExtreme)*2;

    int canvasHeight, canvasWidth;

    if (Y_MAX_ASSUMED < (treeHeight+2)*Y_DIS)
        canvasHeight = (treeHeight+2)*Y_DIS;
    else
        canvasHeight = Y_MAX_ASSUMED;

    if (X_MAX_ASSUMED < (treeWidth)*X_DIS)
        canvasWidth = (treeWidth)*X_DIS;
    else 
        canvasWidth = X_MAX_ASSUMED;

    // Creating html file
    sprintf(fileName,"%s/Binary-tree-%d.html",folderName, callTimes);
    FILE* htmlFile = fopen(fileName,"w");

    if (htmlFile==NULL){
        printf("\n --- Couldn't create/open a file in this directory --- \n");
        return;
    }
    // adding the Canvaswidth, canvasheight and linking the js..
    if (isRB == 1)
        fprintf(htmlFile,"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Binary tree</title><style>body {background-color: %s;margin: 0;}</style></head><body><canvas id=\"myCanvas\" width=\"%d\" height=\"%d\"></canvas><script src=\"script-%d.js\"></script></body></html>",GREY_COLOR,canvasWidth, canvasHeight,callTimes);
    else
        fprintf(htmlFile,"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Binary tree</title><style>body {background-color: %s;margin: 0;}</style></head><body><canvas id=\"myCanvas\" width=\"%d\" height=\"%d\"></canvas><script src=\"script-%d.js\"></script></body></html>",DEFAULT_BG_COLOR,canvasWidth, canvasHeight,callTimes);

    fclose(htmlFile);

    //Writing the root coordinates in to jsFile1 (script-%d.js)
    fprintf(jsFile1, "const ROOT_XCOR = %d;\n", canvasWidth/2);
    fprintf(jsFile1, "const ROOT_YCOR = %d;\n", (canvasHeight - treeHeight*Y_DIS)/2);

    jsFile2 = fopen("jsFile2.js","r");
    while (fgets(buffer, sizeof(buffer), jsFile2) != NULL) 
        fputs(buffer, jsFile1);                 //adding contents of jsfile2 to jsfile1(script-%d.js)
    fclose(jsFile2);
    remove("jsFile2.js");                      //deleting jsfile2.js

    // if (customString){
    //     fprintf(jsFile1, "\nctx.font = \"24px Arial\";\nctx.fillStyle = \"white\";\nctx.fillText(\"%s\", ROOT_XCOR, ROOT_YCOR);\n",customString);
    // }
    fprintf(jsFile1, "\n});\n");
    fclose(jsFile1);

    sprintf(buffer, "xdg-open \"%s/Binary-tree-%d.html\" 2>/dev/null", folderName, callTimes); //opening the html file..
    system(buffer);
}

static void dispRBTree(RBNode *root){

    // va_list args;
    // va_start(args, root);
    // char* customString = va_arg(args, char*);

    dispTreeMain((void *)root,1);//, customString);
}

static void dispNodeTree(Node* root){

    // va_list args;
    // va_start(args, root);
    // char* customString = va_arg(args, char*);

    dispTreeMain((void *)root, 0);//, customString);
}