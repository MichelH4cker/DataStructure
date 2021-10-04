#include "removal.h"

/*
void removeFirstNode(){

}*/

void removeLastNode(struct Node **head){
    struct Node *node = *head;
    struct Node *previousNode;
    // verificar se a lista está vazia

    while (node->next != NULL){
        previousNode = node;
        node = node->next;
    }

    free(node);
    previousNode->next = NULL;
}

/*
void pop(){

}*/