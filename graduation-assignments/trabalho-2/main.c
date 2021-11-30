#include "main.h"

void destroyList(struct Node **head_ref){
    struct Node *currentNode = *head_ref;
    struct Node *helperNode = *head_ref;

    while (currentNode != NULL){
        helperNode = currentNode->next;
        free(currentNode);
        currentNode = helperNode;
    }
    
    *head_ref = NULL;
}

int main (){

    return 0;
}