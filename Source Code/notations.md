## Naming convention

Kebab  : Filename               
Camel  : Variable, Functions
Pascal : Structs
Snake  : Constants, Macros


## Regarding integer pointers or arrays returned by functions

    If a function returns an integer array i.e if its return type is int *, then the first element of the array is its size
    So the first element/integer of the array is reserved for its size.

    For example: 

    ```C
    int *sampleFunction(){
        ....
        ....
    }
    

    void main(){
        int *arr = sampleFunction;
        int arrSize = arr[0];               //size of the array arr is stored in arr[0]
        for (int a = 1 ; a <= size ; a++)
            printf("%d", arr[a]);
    }
    ```

    arr = {5,0,1,2,3,4} --> arr[0] = 5 as there are 5 elements in it, 0,1,2,3,4
    arr = {0}           --> arr[0] = 0 as there are no elements in it
