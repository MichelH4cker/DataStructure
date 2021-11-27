#include "insertion.h"

void push(struct Data data, struct Node **head_ref){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    if (node == NULL){ // não alocado
        return;
    }

    node->data = data;
    node->next = (*head_ref);
    *head_ref = node;

}

void append(struct Data data, struct Node **head_ref){
    

} 