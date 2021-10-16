#include "insertion.h"

void crescentInsert(struct Node **head, float inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;
        
    struct Node *currentNode = *head;

    if (*head == NULL || (*head)->data >= newNode->data){   
        newNode->next = *head;
        *head = newNode; 
        return;
    } else {
        
        currentNode = *head;
        while (currentNode->next != NULL && currentNode->next->data < newNode->data){
            
            currentNode = currentNode->next;    
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}

void descendingInsert(struct Node **head, float inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    

    struct Node *currentNode = *head;

    if (*head == NULL || (*head)->data <= newNode->data ){   
        newNode->next = *head;
        *head = newNode; 
        return;
    } else {
        currentNode = *head;
        while (currentNode->next != NULL && currentNode->next->data > newNode->data){
            
            currentNode = currentNode->next;    
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}