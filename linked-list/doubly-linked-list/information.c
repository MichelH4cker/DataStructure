#include "information.h"

void showAllNodes(struct Node *head_ref){
    if (head_ref == NULL) return;
    
    struct Node *currentNode = head_ref;
    
    while (currentNode != NULL){
        printf("%d %s %f \n", currentNode->data.dataInteger, currentNode->data.dataString, currentNode->data.dataFloat);
        currentNode = currentNode->next;
    }
}