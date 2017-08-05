//
//  main.c
//  traversals
//
//  Created by Md Tahsin Sharif on 2017-02-25.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

//STRUCT NODE
typedef struct node{
    uint32_t data;
    struct node* right;
    struct node* left;
}node_t;


//RETURNS HEIGHT OF TREE
uint32_t height(node_t* root){
    if (root==NULL)
        return 0;
    uint32_t left_height = height(root->left);
    uint32_t right_height = height(root->right);
    
    return (left_height>right_height? left_height+1:right_height+1);
}

//breadth-first traversal
void printLevel(node_t* root, uint32_t height){
    if (root==NULL) return;
    if (height==1) printf("%d ", root->data);
    else if (height > 1){
        printLevel(root->left, height-1);
        printLevel(root->right, height-1);
    }
}

node_t* new_node (uint32_t data){
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root->data = data;
    root->right = root->left = NULL;
    return root;
}

void breadth_first_traversal(node_t* root){
    
    if (root==NULL) return;
    uint32_t height_tree = height(root);
    
    for (int i = 1; i<=height_tree; i++){
        printLevel(root, i);
    }
}

void pre_order_traversal(node_t* root){
    if (root==NULL) return;
    
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void in_order_traversal(node_t* root){
    if (root==NULL)return;
    
    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

void post_order_traversal(node_t* root){
    if (root==NULL) return;
    
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

void choose_traversal(uint32_t input, node_t* root){
    //use lookup to select traversal
    static void (*traversals[])(node_t*) = { pre_order_traversal, in_order_traversal,
                                             post_order_traversal, breadth_first_traversal};
    
    static char *names_traversal[] = {"Pre-order","In-Order","Post-Order", "Breadth-first"};
    
    printf("%s Traversal: ", names_traversal[input]);
    traversals[input](root);
}

int main(int argc, const char * argv[]) {
    //make the tree
    node_t* root = (node_t*)malloc(sizeof(node_t));
    root = new_node(1);
    root->right = new_node(3);
    root->left = new_node(2);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    
    //user input to choose traversal
    uint32_t input = -1;
    while (input < 0 || input > 3){
        printf("\nPlease input the type of traversal required: ");
        scanf("%u", &input);
    }
    printf("\nPrinting in ");
    choose_traversal(input, root);
    
    
    return 0;
}
