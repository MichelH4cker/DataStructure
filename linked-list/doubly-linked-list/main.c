#include "main.h"

void destroyList(struct Node **head_ref){
    struct Node *currentNode  = *head_ref;
    struct Node *helperNode = *head_ref;

    while (currentNode != NULL){
        helperNode = currentNode->next;
        free(currentNode);
        currentNode = helperNode;
    }

    *head_ref = NULL;
}

int main (){
    // DADOS PARA USO 
    struct Data data1 = {1, "palavras", 7.5};
    struct Data data2 = {2, "teste", 452.4};
    struct Data data3 = {3, "vscode", 12.8};
    // --- //

    struct Node *head = NULL; 

    push(data1, &head);
    push(data2, &head);
    push(data3, &head);

    deleteSpecific(&head, 2);
    //deleteFirst(&head);
    //deleteLast(&head);

    printf("O número de nós da lista é: %d \n", len(head));

    showAllNodes(head);

    destroyList(&head);

    return 0;
}