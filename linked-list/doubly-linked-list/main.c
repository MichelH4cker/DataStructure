#include "main.h"

int main (){
    // DADOS PARA USO 
    struct Data data1 = {12, "palavras", 7.5};
    struct Data data2 = {5, "teste", 452.4};
    struct Data data3 = {56, "vscode", 12.8};
    // --- //

    struct Node *head = NULL; 

    push(data1, &head);
    push(data1, &head);
    printf("vai dar merda no append \n");
    append(data2, &head);

    showAllNodes(head);

    return 0;
}