#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int calcSize(struct Node* node){
    int size = 0;
    while(node != NULL){
        node = node -> next;
        size++;
    }
    return size;
}

void insertStart(struct Node* *head, int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    newNode -> data = data;
    newNode -> next = *head;
    
    *head = newNode;
}

void insertLast(struct Node* *head, int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertpos(int pos, int data, struct Node* *head){
    int size = calcSize(*head);
    if(pos < 1 || pos > size){
        printf("Invalid Size\n");
    }
    else{
        struct Node* temp = *head;
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> data = data;
        newNode -> next = NULL;
        
        while(--pos)
            temp = temp -> next;
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void display(struct Node* node){
    while(node != NULL){
        printf("%d ",node->data);
        node = node -> next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    
    insertStart(&head,10);
    insertStart(&head,20);
    
    insertLast(&head,30);
    
    display(head);
    return 0;
}
