#include "insertion.h"
#include "main.h"

void push(struct Node **head, struct Data inputData){
    struct Node *node;
    node = malloc(sizeof(struct Node));

    if (node == NULL || head == NULL){
        return; //error 
    } else {
        node->data = inputData;     // novo nó recebe o dado de entrada
        node->next = (*head);       // próximo nó recebe o conteúdo antigo da head
        *head = node;               // conteúdo do ponteiro head recebe novo nó

        return;
    }

}   

void append(struct Node **head, struct Data inputData){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->data = inputData;
    node->next = NULL;

    struct Node *lastNode = *head;
    // falta checar se a lista está vazia
    // ou seja, se não possui head
    if (node == NULL || head == NULL){
        return;
    } else {
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }

        lastNode->next = node;

        return;
    }    
}

// crescent order
void sortedInsert(struct Node **head, struct Data inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;
    
    
    struct Node *currentNode = *head;

    // miss special case where only existis head
    // or list didnt has any data
    if (*head == NULL || (*head)->data.dataInteger >= newNode->data.dataInteger ){   
        newNode->next = *head;
        *head = newNode; 
        return;
    } else {
        
        currentNode = *head;
        while (currentNode->next != NULL && currentNode->next->data.dataInteger < newNode->data.dataInteger){
            
            currentNode = currentNode->next;    
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    return;
}