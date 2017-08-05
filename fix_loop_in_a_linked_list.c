//
//  main.c
//  Fix a looped linked list
//
//  Created by Md Tahsin Sharif on 2017-05-11.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>

typedef struct node{
    struct node* next;
    uint32_t data;
}node_t;

node_t* find_and_remove_loop(node_t* head){
    node_t* slow =  head;
    node_t* fast = head;
    while (slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow = slow->next;
    uint32_t loop_len = 1;
    while (slow!=fast){
        slow = slow->next;
        ++loop_len;
    }
    
    slow = fast = head;
    uint32_t j = 0;
    while (j<loop_len){
        fast = fast->next;
        j++;
    }
    
    while (slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = NULL;
    
    return head;
}

int main(int argc, const char * argv[]) {
    return 0;
}
