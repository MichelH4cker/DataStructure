#include "main.h"

int main (){
    // DADOS PARA USO 
    struct Data data1 = {12, "palavras", 7.5};
    struct Data data2 = {5, "teste", 452.4};
    struct Data data3 = {56, "vscode", 12.8};
    // --- //

    struct Node *head = NULL; 

    int result = emptyList(&head);

    printf("1 se estiver vazia, 0 se estiver cheia: \n");
    printf("resultado: %d \n", result);

    push(data1, &head);
    
    showAllNodes(&head);

    return 0;
}