#include "insertion.h"

int pushHome(List *head, struct Data inputData){
    if (head == NULL){
        return 0;
    }

    Node *node;
    node = malloc(sizeof(Node));
    if (node == NULL){
        return 0;
    }

    node->data = inputData; // novo nó recebe o dado de entrada
    node->next = (*head);     // próximo nó recebe o conteúdo antigo da head
    *head = node;           // conteúdo do ponteiro head recebe novo nó

    return 1;
}   