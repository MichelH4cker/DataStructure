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