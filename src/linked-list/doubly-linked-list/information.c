#include "information.h"

int len(struct Node *head_ref){
    struct Node *currentNode = head_ref;

    int numberOfNodes = 0;
    while (currentNode != NULL){
        currentNode = currentNode->next;
        numberOfNodes++;
    }

    return numberOfNodes;
}

void showAllNodes(struct Node *head_ref){
    if (head_ref == NULL) return; // lista vazia
    
    struct Node *currentNode = head_ref;
    
    while (currentNode != NULL){
        printf("%d %s %f \n", currentNode->data.dataInteger, currentNode->data.dataString, currentNode->data.dataFloat);
        currentNode = currentNode->next;
    }
}