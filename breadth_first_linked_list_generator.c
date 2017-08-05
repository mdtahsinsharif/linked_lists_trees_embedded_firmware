//
//  breadth_first_linked_list_generator.c
//  
//
//  Created by Md Tahsin Sharif on 2017-08-05.
//
//

#include "breadth_first_linked_list_generator.h"

/*
given a bst, create a LL out of all the nodes at each depth (if you have a tree with depth D, you will have D LLs)

 NOTE: this question is only a pseudo-code of the algorithm, therefore it hasnt been as such that it compiles
*/

void pre_order(node* root, int level, vector v){
    if(root==NULL){
        //level--;
        return;
    }
    v[level] = LL;
    insert_into_LL(LL,level, vector v);
    pre_order(root->left, level+1, v);
    pre_order(root->right, level+1, v);
}
