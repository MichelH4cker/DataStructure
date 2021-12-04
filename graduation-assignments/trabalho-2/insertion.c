#include "insertion.h"

int switchAxis(int mainAxis, int currentAxis){
    if (mainAxis == X){
        if (currentAxis == X){
            return Y;
        } 
        return Z;
             
    } else if (mainAxis == Y){
        if (currentAxis == Y){
            return X;
        }
        return Z;
        
    } else {
        if (currentAxis == Z){
            return X;
        }
        return Y;
    }
}

void hierarchyOfAxis(struct Node **newNode_ref, struct Node **currentNode_ref, int mainAxis, int currentAxis){

    struct Node *currentNode = *currentNode_ref;
    struct Node *newNode = *newNode_ref;

    if (currentNode == NULL) return;
    
    if (currentNode->data.coordinate[currentAxis] == currentNode->next->data.coordinate[currentAxis]){ 
        currentAxis = switchAxis(mainAxis, currentAxis);
        hierarchyOfAxis(&newNode, &currentNode, mainAxis, currentAxis);

    } else if (currentNode->next->data.coordinate[currentAxis] > currentNode->data.coordinate[currentAxis]) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;

    } else {
        newNode->next = currentNode->next;
        currentNode = newNode;
    }
}

void push(struct Node **head_ref, struct Data data){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){ // não alocado  
        return;
    }

    newNode->data = data;                 
    newNode->timesAccessed = 0;

    newNode->next = (*head_ref);          
    newNode->previous = NULL;     

    if (*head_ref != NULL){
        newNode->timesAccessed++;
        (*head_ref)->previous = newNode;  
    }

    (*head_ref) = newNode;                
}

void append(struct Node **head_ref, struct Data data){
    struct Node *lastNode = *head_ref;
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return; // não alocado 

    newNode->timesAccessed = 0;
    newNode->data = data;       
    newNode->next = NULL;       

    // a lista ainda está vazia, primeiro elemento a ser inserido
    if ((*head_ref) == NULL){   
        newNode->previous == NULL;
        (*head_ref) = newNode;
        newNode->timesAccessed++;
        return;
    }

    while (lastNode->next != NULL){
        lastNode = lastNode->next;
        newNode->timesAccessed++;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
}

void sortedInsert(struct Node **head_ref, struct Data data, int mainAxis){
    struct Node *currentNode = *head_ref;
    struct Node *newNode;

    int currentAxis = mainAxis;

    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->timesAccessed = 0;

    if ((*head_ref) == NULL){ //cabeça vazia
        *head_ref = newNode;
        newNode->timesAccessed++;
    } else if ((*head_ref)->data.coordinate[mainAxis] >= newNode->data.coordinate[mainAxis]) {  //cabeçalho já é o maior
        (*head_ref)->previous = newNode;
        newNode->next = *head_ref;
        *head_ref = newNode;
        newNode->timesAccessed++;
    } else {
        currentNode = *head_ref;

        while (currentNode->next != NULL && currentNode->next->data.coordinate[mainAxis] < newNode->data.coordinate[mainAxis]) {
            currentNode = currentNode->next;
            newNode->timesAccessed++;
        }

        // ao sair do nó o próximo nó é nulo
        // ao sair do while, sabemos que o próximo nó é maior OU igual ao ao nó atual

        if (currentNode->next == NULL){
            newNode->timesAccessed++;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        
        hierarchyOfAxis(&newNode, &currentNode, mainAxis, currentAxis);
    }   
}
