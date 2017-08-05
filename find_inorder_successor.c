//
//  find_inorder_successor.c
//  
//
//  Created by Md Tahsin Sharif on 2017-08-05.
//
//

#include "find_inorder_successor.h"

/*find the next node (inorder successor) of a given node in a BST. you may assume that each node has a link to its parent

i.e. node->parent
*/
node* Node {
    node* left;
    node* right;
    node* parent;
}

void inorder(node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

node* find_successor(node* root){
    
    //first
    if (root->right == NULL){
        
        while (root->parent->right == root){
            root = root->parent;
        }
        if (root->parent->left == root ){
            return root->parent;
        } else if (root->parent == NULL){
            return NULL;
        }
    }
    
    //second
    if (root->right!=NULL){
        root = root->right;
        while (root->left!=NULL){
            root = root->left;
        }
        return root;
    }
    
}
