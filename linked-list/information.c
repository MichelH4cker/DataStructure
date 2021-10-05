#include "information.h"

void showAllNodes(struct Node *head){
    struct Node *newNode = head;    
    
    int position = 1;
    while (newNode != NULL){
        printf("nó %d: \n", position);
        printf("%d - %s - %f \n", newNode->data.dataInteger, newNode->data.dataString, newNode->data.dataFloat);
        printf("\n");

        newNode = newNode->next;
        position++;
    }
    
}

int len(struct Node *head){
    int len = 0;
    struct Node *node = head;
    
    if (head == NULL){
        return 0;
    }  
    while (node != NULL){
        node = node->next;
        len++;
    }
    
    return len;
}

struct Node* search(struct Node **head, int key){
    //verifcação de lista vazia

    // o nó de retorno é sempre o anterior ao da chave
    struct Node *node = *head; 
    while (node->next != NULL){
        if (node->next->data.dataInteger == key){
            
            return node;
        }
        
        node = node->next;       
    }
    node = NULL;
    return node;
}