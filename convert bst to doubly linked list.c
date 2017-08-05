//
//  main.c
//  convert to DLL from bst
//
//  Created by Md Tahsin Sharif on 2017-02-24.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node_t;

/* This is the core function to convert Tree to list. This function follows
 steps 1 and 2 of the above algorithm */
node_t* bintree2listUtil(node_t* root)
{
    // Base case
    if (root == NULL)
        return root;
    
    // Convert the left subtree and link to root
    if (root->left != NULL)
    {
        // Convert the left subtree
        node_t* left = bintree2listUtil(root->left);
        
        // Find inorder predecessor. After this loop, left
        // will point to the inorder predecessor
        for (; left->right!=NULL; left=left->right);
        
        // Make root as next of the predecessor
        left->right = root;
        
        // Make predecssor as previous of root
        root->left = left;
    }
    
    // Convert the right subtree and link to root
    if (root->right!=NULL)
    {
        // Convert the right subtree
        node_t* right = bintree2listUtil(root->right);
        
        // Find inorder successor. After this loop, right
        // will point to the inorder successor
        for (; right->left!=NULL; right = right->left);
        
        // Make root as previous of successor
        right->left = root;
        
        // Make successor as next of root
        root->right = right;
    }
    
    return root;
}

// The main function that first calls bintree2listUtil(), then follows step 3
//  of the above algorithm
node_t* bintree2list(node_t *root)
{
    // Base case
    if (root == NULL)
        return root;
    
    // Convert to DLL using bintree2listUtil()
    root = bintree2listUtil(root);
    
    // bintree2listUtil() returns root node of the converted
    // DLL.  We need pointer to the leftmost node which is
    // head of the constructed DLL, so move to the leftmost node
    while (root->left != NULL)
        root = root->left;
    
    return (root);
}

/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
node_t* newNode(int data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node_t *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}

/* Driver program to test above functions*/
int main()
{
    // Let us create the tree shown in above diagram
    node_t *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    
    // Convert to DLL
    node_t *head = bintree2list(root);
    
    // Print the converted list
    printList(head);
    
    return 0;
}
