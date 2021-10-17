#include "insertion.h"

void merge(){

}

void crescentInsert(struct Node **head_ref, float inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;
        
    struct Node *currentNode = *head_ref;

    if (*head_ref == NULL || (*head_ref)->data >= newNode->data){   
        newNode->next = *head_ref;
        *head_ref = newNode; 
        return;
    } else {
        currentNode = *head_ref;
        while (currentNode->next != NULL && currentNode->next->data < newNode->data){    
            currentNode = currentNode->next;    
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}

void descendingInsert(struct Node **head_ref, float input){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = input;
        
    struct Node *currentNode = *head_ref;

    if (*head_ref == NULL || (*head_ref)->data <= newNode->data){   
        newNode->next = *head_ref;
        *head_ref = newNode; 
        return;
    } else {
        currentNode = *head_ref;

        while (currentNode->next != NULL && currentNode->next->data > newNode->data){
            
            currentNode = currentNode->next;    
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}

void append(struct Node **head, struct Data inputData){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    if(node == NULL){
        return;
    }
    node->data = inputData;
    node->next = NULL;

    struct Node *lastNode = *head;
    
    if ((*head) == NULL){ // lista vazia insere no início
        *head = node;
        return;
    } else {
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }

        lastNode->next = node;
        return;
    }    
}