#include "linked-list.h"

void append(struct Node **head, struct Search data){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    if(node == NULL){
        return; // NAÕ ALOCOU
    }

    node->search = data;
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

void pop(struct Node **head, char *prefix){
    struct Node *node = *head;
    struct Node *previous = *head;
    if (node != NULL && (strcmp(node->search.prefix, prefix) != 0)){
        printf("é diferente \n");
        *head = node->next;
        free(node);
        return;
    }
    
    while (node != NULL && (strcmp(node->search.prefix, prefix) == 0)){
        printf("está no while \n");
        previous = node;
        node = node->next;
    }
    if (node == NULL){
        return;
    }

    
}

/*

MA MACACO 33
TA TATU 13
MA MARIMBONDO 20
TA TARTARUGA 15
MA MARIPOSA 2
TA TAMANDUA 10
MA MARISCO 1
TA TAINHA 5
MA MARITACA 5
TA TARANTULA 12
MAR MARMOTA 12
ZEB ZEBRA 1
MAR MARRECO 7
ARA ARANHA 15
ARAR ARARA 15

*/