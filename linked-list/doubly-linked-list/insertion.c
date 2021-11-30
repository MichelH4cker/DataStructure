#include "insertion.h"

void push(struct Data data, struct Node **head_ref){
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

void append(struct Data data, struct Node **head_ref){
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

void sortedInsert(struct Data data, struct Node **head_ref){
    struct Node *lastNode = *head_ref;
    struct Node *currentNode = *head_ref;
    struct Node *newNode;
    
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){
        return;
    }  // verificação e alocação

    newNode->data = data;
    
    if ((*head_ref) == NULL){
        *head_ref = newNode;
    } else if ((*head_ref)->data.dataInteger >= newNode->data.dataInteger) { //cabeçalho já é o maior
        (*head_ref)->previous = newNode;
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        currentNode = *head_ref;

        while (currentNode->next != NULL && currentNode->next->data.dataInteger < newNode->data.dataInteger) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }   
}