#include <stdio.h>
#include <time.h>


#define LINKED_LIST_SIZE 5
#define LINKED_LIST_VALUE_CONSTANT 1000

typedef struct node {
    struct node* next;
    struct node* random;
    int data;
} node_t;

node_t* create_node(int data){
    node_t *new_n = (node_t*)malloc(sizeof(node_t));
    new_n->data = data;
    new_n->next = NULL;
    new_n->random = NULL;
    return new_n;
}

node_t* link_lists(node_t* head){
    
    node_t* temp = head;
    while (temp!= NULL){
        node_t* new_n = create_node(temp->data);
        node_t* old = temp->next;
        temp->next = new_n;
        new_n->next = old;
        new_n->random = temp;
        temp = old;
    }
    return head;
}

node_t* fix_random_pointers(node_t* head){
    node_t* temp = (head)->next;
    node_t* temp_prev = (head);
    while(temp->next!=NULL){
        temp->random = temp->random->random->next;
        temp_prev = temp->next;
        temp->next = temp_prev->next;
        temp = temp->next;
    }
    return (head)->next;
}

node_t* create_old_list(){
    node_t* head = create_node(LINKED_LIST_VALUE_CONSTANT*2);
    node_t* temp = head;
    int i = 1, r = 0, j = 0, count = 0;
    /*
     srand(time(NULL));
     while (i!=LINKED_LIST_SIZE){
     temp->next = create_node(LINKED_LIST_VALUE_CONSTANT/i);
     temp = temp->next;
     i++;
     }
     
     while (j<LINKED_LIST_SIZE){
     temp = head;
     node_t* temp_for_prev = temp;
     r = rand() % (LINKED_LIST_SIZE-j);
     while (count<r){
     temp_for_prev = temp_for_prev->next;
     count++;
     }
     if (temp_for_prev == NULL)
     temp->random = NULL;
     temp->random = temp_for_prev;
     temp = temp->next;
     count = 0;
     j++;
     }
     
     */
    head->next = create_node(LINKED_LIST_VALUE_CONSTANT/4);
    head->next->next = create_node(LINKED_LIST_VALUE_CONSTANT/8);
    head->next->next->next = create_node(LINKED_LIST_VALUE_CONSTANT/16);
    head->next->next->next->next = create_node(LINKED_LIST_VALUE_CONSTANT/32);
    head->next->next->next->next->next = create_node(LINKED_LIST_VALUE_CONSTANT/64);
    
    head->random = head->next;
    head->next->random = head->next->next->next->next;
    head->next->next->random = head->next->next;
    head->next->next->next->random = head;
    head->next->next->next->next->random = head->next;
    head->next->next->next->next->next->random = head->next->next->next;
    
    return head;
}

int main()
{
    
    node_t* head = create_old_list();
    node_t* old_head = head;
    
    head = link_lists(head);
    head = fix_random_pointers(head);
    printf("Old: %u %u %u %u %u \n", old_head->random->data, old_head->next->random->data, old_head->next->next->random->data, old_head->next->next->next->random->data, old_head->next->next->next->next->random->data);
    printf("New: %u %u %u %u\n", head->random->data, head->next->random->data, head->next->next->random->data, head->next->next->next->random->data);
    /*
     srand(time(NULL));
     int r;
     int i = 1;
     while (i!=LINKED_LIST_SIZE){
     printf(" %u ", r);
     r = rand() % (LINKED_LIST_SIZE-i);
     i++;
     }
     */
    
    
    return 0;
}
