#include "deletion.h"

void deleteFirst(struct Node **head_ref){
    struct Node *newHead_ref = (*head_ref)->next;
    newHead_ref->previous = NULL;

    (*head_ref) = newHead_ref;
}

void deleteLast(struct Node **head_ref){
    struct Node *lastNode;
    struct Node *currentNode = *head_ref;

    while (currentNode->next != NULL){
        lastNode = currentNode;
        currentNode = currentNode->next;
    }

    lastNode->next = NULL;
    currentNode = lastNode;
    
}

void deleteSpecific(struct Node **head_ref, int nodeNumber){
    if (*head_ref == NULL) return;
    
    struct Node *currentNode = *head_ref;
    struct Node *lastNode;

    int cont = 1;
    while (currentNode != NULL){
        if (cont == nodeNumber) {
            lastNode->next = currentNode->next;
            currentNode = lastNode;
            return;
        }
        lastNode = currentNode;
        currentNode = currentNode->next;
        cont++;
    }
}