#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data[50];
	struct node *left_child;
	struct node *right_child;
};

struct node* createNode(char *key)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	strcpy(newNode->data, key);
	newNode->left_child = NULL;
	newNode->right_child = NULL;
	
	return newNode;
}


struct node* Search(struct node *rootNode, char *key)
{
    if(rootNode==NULL || strcmp(rootNode->data, &*key)==0) //if rootNode->data is the one being searched then number is found
        return rootNode;
        
    else if(strcmp(&*key, rootNode->data) < 0 ) // strcmp < 0 if first unmatched char is less than second, search the left subtree
        return Search(rootNode->right_child, &*key);
    else // strcmp > 0 if first unmatched char is greater than second, search the right subtree
        return Search(rootNode->left_child, &*key);
}

struct node* Insert(struct node* rootNode, char *key) 
{ 
    if (rootNode == 0) //if root doesnt exist, create a new one
		return createNode(&*key);
		 
  	else if (strcmp(&*key, rootNode->data) < 0 ) //strcmp < 0 if first unmatched char is less than second, search the left subtree
        rootNode->left_child  = Insert(rootNode->left_child, &*key); 
    else //strcmp > 0 if first unmatched char is greater than second, search the right subtree
        rootNode->right_child = Insert(rootNode->right_child, &*key);
    return rootNode; 
} 

void Inorder(struct node *rootNode) 
{ 
    if (rootNode != NULL) 
    { 
        Inorder(rootNode->left_child); 
        printf("%s \n", rootNode->data); 
        Inorder(rootNode->right_child); 
    }
} 

void Delete(struct node *rootNode) 
{ 
    if (rootNode == NULL) 
		return; 
  
    /* first delete both subtrees */
    Delete(rootNode->left_child); 
    Delete(rootNode->right_child); 
  
    printf("\n Deleting node: %s", rootNode->data); 
    free(rootNode); 
} 

int main(){
	
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
