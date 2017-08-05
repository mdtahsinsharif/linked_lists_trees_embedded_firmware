//
//  main.c
//  add two linked lists (addition)
//
//  Created by Md Tahsin Sharif on 2017-05-13.
//  Copyright © 2017 Md Tahsin Sharif. All rights reserved.
//

#include <stdio.h>
/*
   Two Linked Lists of integers are given in reversed order. Add them up and represent the result
   in the same format.
   As example, the number 439 will be represented as 9->3->4. 145 will be 5->4->!
   The result of (439+145) = 584 will be a linked list of 4->8->5
*/

typedef struct node{
    struct node* next;
    int data;
}node_t;

node_t* new_node(int val){
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

uint32_t length(node_t* head1){
    
    uint32_t n = 0;
    if (head1 == NULL) return n;
    if (head1->next == NULL) return (++n);
    
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head = head1;
    while (head->next!=NULL){
        head = head->next;
        ++n;
    }
    return n;
}

node_t* addition(node_t* head1, node_t* head2){
    int carry = 0, factor = 10;
    int val = (head1->data) + (head2->data) + carry;
    node_t* temp = new_node(val%factor);
    node_t* head = temp;
    
    carry = val/factor;
    while ((head1->next!=NULL || head2->next!=NULL)){
        head1 = head1->next;
        head2 = head2->next;
        val = (head1->data) + (head2->data) + carry;
        temp->next = new_node(val%factor);
        carry = val/factor;
        temp = temp->next;
        
    }
    
    if (carry!=0){
        val = carry;
        temp->next = new_node(val);
    }
    return head;
}

node_t* reverse_list(node_t* head){
    node_t* first = head;
    node_t* second = head->next;
    node_t* third = head->next->next;
    first->next = NULL;
    
    while (third != NULL){
        second->next = first;
        first = second;
        second = third;
        third = third->next;
    }
    
    second->next = first;
    
    return second;
}

node_t* padding_(node_t* head, uint32_t diff){
    
    if (diff == 0) return head;
    
    node_t* temp = head;
    
    while (temp->next!=NULL){
        temp = temp->next;
    }
    
    node_t* padding = new_node(0);
    temp->next = padding;
    
    for (int i=1; i<diff; i++){
        padding->next = new_node(0);
        padding = padding->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    
    node_t* head1 = new_node(1);
    head1->next = new_node(1);
    head1->next->next = new_node(9);
    
    node_t* head2 = new_node(1);
    head2->next = new_node(2);
    head2->next->next = new_node(9);
    head2->next->next->next = new_node(9);
    head2->next->next->next->next = new_node(1);
    head2->next->next->next->next->next = new_node(9);
    
    signed int diff = (length(head1)) - (length(head2));
    printf("Diff: %d\n", diff);
    
    if (diff > 0)
        head2 = padding_(head2, diff);
    else if (diff < 0)
        head1 = padding_(head1, (-1)*diff);
    
    printf("\nHead1 List: ");
    node_t* tail1 = head1;
    while (tail1!=NULL){
        printf(" %u ", tail1->data);
        tail1 = tail1->next;
    }
    
    node_t* tail2 = head2;
    printf("\n\nHead2 List: ");
    while (tail2!=NULL){
        printf(" %u ", tail2->data);
        tail2 = tail2->next;
    }
    
    node_t* new_list = addition(head1, head2);
    
    node_t* reversed_head = reverse_list(new_list);
    
    printf("\n\nAnswer: ");
    while (reversed_head!=NULL){
        printf(" %u ", reversed_head->data);
        reversed_head = reversed_head->next;
    }
    return 0;
}
