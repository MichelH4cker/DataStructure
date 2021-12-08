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

void hierarchyOfAxis(struct Node **headSon_ref, struct Node **newNode_ref, int mainAxis, int currentAxis){
    struct Node *currentNode = *headSon_ref;

    if ((*headSon_ref)->data.coordinate[currentAxis] > (*newNode_ref)->data.coordinate[currentAxis]){
        (*newNode_ref)->timesAccessed++;

        (*headSon_ref)->previous = (*newNode_ref);
        (*newNode_ref)->next = (*headSon_ref);
        (*headSon_ref) = (*newNode_ref);
        
    } else if ((*headSon_ref)->data.coordinate[currentAxis] == (*newNode_ref)->data.coordinate[currentAxis]){
        (*newNode_ref)->timesAccessed++;

        currentAxis = switchAxis(mainAxis, currentAxis);
        struct Node *headGrandSon = (*headSon_ref);
        struct Node *newNodeSon_ref = (*newNode_ref);
        hierarchyOfAxis(&headGrandSon, &newNodeSon_ref, mainAxis, currentAxis);
        (*headSon_ref) = headGrandSon;
    } else {
        currentNode = *headSon_ref;
        while ((currentNode->next != NULL) && (currentNode->next->data.coordinate[currentAxis] <= (*newNode_ref)->data.coordinate[currentAxis])){
            if (currentNode->next->data.coordinate[currentAxis] == (*newNode_ref)->data.coordinate[currentAxis]){
                (*newNode_ref)->timesAccessed++;
                struct Node *headGrandSon = currentNode->next;
                struct Node *newNodeGrandSon = (*newNode_ref);
                
                currentAxis = switchAxis(mainAxis, currentAxis);

                hierarchyOfAxis(&headGrandSon, &newNodeGrandSon, mainAxis, currentAxis);
                
                currentNode->next = headGrandSon;

                return;
            }
            (*newNode_ref)->timesAccessed++;

            currentNode = currentNode->next;
        }
        // caso o while faça com que o currentNode no eixo principal seja maior que o newNode_ref no eixo principal
        if (currentNode->data.coordinate[mainAxis] > (*newNode_ref)->data.coordinate[mainAxis]) 
            currentNode = currentNode->previous;
            (*newNode_ref)->timesAccessed++;
        

        (*newNode_ref)->next = currentNode->next;
        currentNode->next = (*newNode_ref);
    }
    
}

void sortedInsert(struct Node **head_ref, struct Data data, int mainAxis, int currentAxis){
    struct Node *currentNode = *head_ref;
    
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->timesAccessed = 0;

    if ((*head_ref) == NULL){ //cabeça vazia
        newNode->timesAccessed++;

        *head_ref = newNode;
    } else if ((*head_ref)->data.coordinate[mainAxis] > newNode->data.coordinate[mainAxis]) {  
        newNode->timesAccessed++;
        (*head_ref)->previous = newNode;
        
        newNode->next = *head_ref;
        
        *head_ref = newNode;
    } else if ((*head_ref)->data.coordinate[mainAxis] == newNode->data.coordinate[mainAxis]){
        newNode->timesAccessed++;

        struct Node *headSon = (*head_ref);
        struct Node *newNode_ref = newNode;
        currentAxis = switchAxis(mainAxis, currentAxis);
        hierarchyOfAxis(&headSon, &newNode_ref, mainAxis, currentAxis);
        (*head_ref) = headSon;
    } else {
        newNode->timesAccessed++;
        currentNode = *head_ref;

        while ((currentNode->next != NULL) && (currentNode->next->data.coordinate[currentAxis] <= newNode->data.coordinate[currentAxis])){
            if (currentNode->next->data.coordinate[mainAxis] == newNode->data.coordinate[mainAxis]){
                newNode->timesAccessed++;

                struct Node *headSon = currentNode->next;
                struct Node *newNodeSon = newNode;

                currentAxis = switchAxis(mainAxis, currentAxis);
                hierarchyOfAxis(&headSon, &newNodeSon,mainAxis, currentAxis);
                
                currentNode->next = headSon;

                return;
            }
            
            currentNode = currentNode->next;
            newNode->timesAccessed++;
        }
        newNode->timesAccessed++;
        newNode->next = currentNode->next;
        currentNode->next = newNode;
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
    newNode->timesAccessed++;

    if (*head_ref != NULL){
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

    newNode->timesAccessed++;
    lastNode->next = newNode;
    newNode->timesAccessed++;
    newNode->previous = lastNode;
}