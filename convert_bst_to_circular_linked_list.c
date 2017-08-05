//
//  main.c
//  convert bst to circular linked list
//
//  Created by Md Tahsin Sharif on 2017-02-25.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node_t;

node_t* new_node(int data){
    
    //making a new node
    node_t* ptr = (node_t*)malloc(sizeof(node_t));
    ptr->data = data;
    
    //point right and left pointers to null
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}

node_t* convert_to_CLL(node_t* root){
    
    if (root == NULL) return root;
    
    //convert left subtree
    if (root->left!=NULL){
        node_t* left = convert_to_CLL(root->left);
        
        while (left->right!=NULL) left = left->right;
        
        //update both pointers between root and left node
        left->right = root;
        root->left = left;
    }
    
    //convert right subtree
    if (root->right != NULL){
        node_t* right = convert_to_CLL(root->right);
        
        while (right->left!=NULL) right = right->left;
        
        //update both pointers between root and right node
        right->left = root;
        root->right = right;
    }
    return root;
}

node_t* convert_to_CLL_start(node_t* root){
    
    if (root == NULL) return root;
    
    //main conversion happens here
    root = convert_to_CLL(root);
    
    node_t* head = (node_t*)malloc(sizeof(node_t));
    node_t* tail = (node_t*)malloc(sizeof(node_t));
    
    //start from the root and traverse left and right to connect the "head" and "tail"
    //of a non-connected doubly linked list
    head = root;
    tail = root;
    
    while (head->left!=NULL) head = head->left;
    while (tail->right!=NULL) tail = tail->right;
    
    head->left = tail;
    tail->right = head;
    
    root = head;
    return root;
}

void printlist(node_t* head){
    if (head == NULL) return;
    int i= 0;
    printf("Printing the list: ");
    for (i = 0; i<12; i++){
        if (i == 6) printf("\nPrinting the list again: ");
        printf("%d ", head->data);
        head = head->right;
    }
}

int heightnew (node_t* root, int n){
    int h;
    if (root->right==NULL) return 1;
    if (root->left == NULL) return 1;
    if(root->right!= NULL){
        return heightnew(root->right, n+1);
    }
    if (root->left!=NULL) {
        return heightnew(root->left, h+1);
    }
    
    return 0;
}

int height (node_t* root){
    if (root == NULL) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    return (lheight>rheight?lheight+1:rheight+1);
}

int main() {

    node_t* root = (node_t*)malloc(sizeof(node_t));
    
    root = new_node(10);
    root->right = new_node(15);
    root->left = new_node(7);
    root->left->left = new_node(2);
    root->left->right = new_node(9);
    root->right->left = new_node(12);
    root->right->left->right = new_node(98);
    
    int height1 = heightnew(root, 0);
    printf("\nHeight: %d\n", height1);
    
    node_t* head = (node_t*)malloc(sizeof(node_t));
    
    head = convert_to_CLL_start(root);
    
    printlist(head);
    
    return 0;
}
