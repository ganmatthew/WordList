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