#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"
#include "bst.c"

int main() {
	
	struct node *root;
	
	root = createNode("hello");
	Insert(root, "how");
	Insert(root, "are");
    Insert(root, "you");
    Insert(root, "today");
    Insert(root, "fine");
    Insert(root, "thank");
    Insert(root, "you");
    Insert(root, "how");
    Insert(root, "about");
    Insert(root, "you");
    Insert(root, "today");
    Insert(root, "is");
    Insert(root, "the");
    Insert(root, "present");
    Insert(root, "tomorrow");
    Insert(root, "is");
    Insert(root, "a");
    Insert(root, "gift");
    
    Inorder(root);
    printf("\n");
    
    Delete(root);
    return 0;
}
