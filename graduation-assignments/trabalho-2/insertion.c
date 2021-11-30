#include "insertion.h"

void push(struct Node **head_ref, struct Data data){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){ // não alocado  
        return;
    }

    newNode->data = data;                 

    newNode->next = (*head_ref);          
    newNode->previous = NULL;     

    if (*head_ref != NULL){
        (*head_ref)->previous = newNode;  
    }

    (*head_ref) = newNode;                
}

void append(struct Node **head_ref, struct Data data){
    struct Node *lastNode = *head_ref;
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return; // não alocado 

    newNode->data = data;       
    newNode->next = NULL;       

    if ((*head_ref) == NULL){   
        newNode->previous == NULL;
        (*head_ref) = newNode;
        return;
    }

    while (lastNode->next != NULL){
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
}