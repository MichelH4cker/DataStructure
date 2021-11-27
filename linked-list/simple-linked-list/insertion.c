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
    if(node == NULL){
        return;
    }
    node->data = inputData;
    node->next = NULL;

    struct Node *lastNode = *head;
    
    if ((*head) == NULL){ // lista vazia insere no início
        *head = node;
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
void increasingInsertion(struct Node **head, struct Data inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;
        
    struct Node *currentNode = *head;

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
        return;
    }
}

void descendingInsert(struct Node **head, struct Data inputData){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;
        
    struct Node *currentNode = *head;

    if (*head == NULL || (*head)->data.dataInteger <= newNode->data.dataInteger ){   
        newNode->next = *head;
        *head = newNode; 
        return;
    } else {
        
        currentNode = *head;
        while (currentNode->next != NULL && currentNode->next->data.dataInteger > newNode->data.dataInteger){
            
            currentNode = currentNode->next;    
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }
}