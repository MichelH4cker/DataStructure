#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

void destroyList(struct Node **head){
    struct Node *currentNode = *head;
    struct Node *nextNode;
    
    while (currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;

    }
    *head = NULL;
}