#include "insertion.h"
#include "main.h"

int push(struct Node **head, struct Data inputData){
    if (head == NULL){
        return 0;
    }

    struct Node *node;
    node = malloc(sizeof(struct Node));
    if (node == NULL){
        return 0;
    }

    node->data = inputData;     // novo nó recebe o dado de entrada
    node->next = (*head);       // próximo nó recebe o conteúdo antigo da head
    *head = node;               // conteúdo do ponteiro head recebe novo nó

    return 1;
}   