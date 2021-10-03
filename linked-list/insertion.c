#include "insertion.h"
#include "main.h"

int push(struct Node **head, struct Data inputData){
    struct Node *node;
    node = malloc(sizeof(struct Node));

    if (node == NULL || head == NULL){
        return 0; //error 
    } else {
        node->data = inputData;     // novo nó recebe o dado de entrada
        node->next = (*head);       // próximo nó recebe o conteúdo antigo da head
        *head = node;               // conteúdo do ponteiro head recebe novo nó

        return 1;
    }

}   

int append(struct Node **head, struct Data inputData){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->data = inputData;
    node->next = NULL;

    struct Node *lastNode = *head;

    if (node == NULL || head == NULL){
        return 0;
    } else {
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }

        lastNode->next = node;

        return 1;
    }    
}