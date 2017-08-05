#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}node_t;

node_t* convert_to_DLL(node_t* root)
{
    //printf("TRACE: %i\n", root->val);
    if (root->left!=NULL)
    {
        node_t* left = convert_to_DLL(root->left);
        
        while (left->right!=NULL) left = left->right;
        
        left->right = root;
        root->left = left;
    }
    
    if (root->right!=NULL)
    {
        node_t* right = convert_to_DLL(root->right);
        
        while (right->left!=NULL) right = right->left;
        
        right->left = root;
        root->right = right;
    }
    //printf("Return: %i\n", root->val);
    return root;
}


int maxValue(node_t* root, int max){
    printf("Current: %i\n", root->val);
    if (root->left!=NULL){
        if (root->left->val > max)
            max = root->left->val; //return this
        printf("Max left: %i\n", max);
        max = maxValue(root->left, max); //
    }
    if (root->right!=NULL){
        if(root->right->val > max)
            max = root->right->val;
        printf("Max right: %i\n", max);
        max =  maxValue(root->right, max);
        
    }
    printf("Return: %i\n", root->val);
    printf("Return max: %i\n", max);
    return max;
}

node_t* new_node (int data){
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root->val = data;
    root->right = root->left = NULL;
    return root;
}

int main()
{
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root = new_node(500);
    root->left = new_node(200);
    root->right = new_node(700);
    root->left->left = new_node(100);
    root->right->left = new_node(600);
    root->right->right = new_node(900);
    root->right->right->right = new_node(1000);
    root->left->left->right = new_node(150);
    root->left->left->right->left = new_node(120);
    root->left->right = new_node(300);
/*
    root = convert_to_DLL(root);
    //printf("Value: %i", root->val);
    
    while (root->left!=NULL) root = root->left;
    while (root!=NULL){
        printf("Value: %i\n", root->val);
        root = root->right;
    }
 */
    int max = maxValue(root, 0);
    printf("\nMax Value: %i\n", max);
    return 0;
}

