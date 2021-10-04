#include "information.h"

void showAllNodes(struct Node *head){
    struct Node *newNode = head;    
    
    int position = 1;
    while (newNode != NULL){
        printf("nó %d: \n", position);
        printf("%d - %s - %f \n", newNode->data.dataInteger, newNode->data.dataString, newNode->data.dataFloat);
        printf("\n");

        newNode = newNode->next;
        position++;
    }
    
}

int len(struct Node *head){
    int len = 0;
    struct Node *node = head;
    
    if (head == NULL){
        return 0;
    }  
    while (node != NULL){
        node = node->next;
        len++;
    }
    
    return len;
}