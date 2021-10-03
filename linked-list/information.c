#include "information.h"

void showAllNodes(struct Node *head){
    struct Node *newNode = head;    
    
    while (newNode != NULL){
        printf("%d - %s - %f \n", newNode->data.dataInteger, newNode->data.dataString, newNode->data.dataFloat);
        newNode = newNode->next;
    }
    
}