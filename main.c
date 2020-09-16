#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_LOGS 1
typedef char String[50];

#include "bst.h"
#include "bst.c"
#include "tokenizer.c"

int main() {
    /*
      TODO: Get string array to work with BST functionality
    */
    String * strArray; 
    struct node * root;
    int i;

    if (readFile(strArray) != 0)
    {
        root = createNode(strArray[0]);
        for (i = 1; i < sizeof(strArray); i++)
        {
            Insert(root, strArray[i]);
        }
        
        Inorder(root);
        printf("\n");
        //Delete(root);
    }
    else
        return 0;
}
