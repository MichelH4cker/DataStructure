#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    struct Data data2 = {3, "amanda", 7.5};
    struct Data data3 = {7, "append", 2.5};
    struct Data data4 = {5, "ordenada", 3.14};
    //struct Node *head = createList(); // pointer to pointer
    struct Node *head = NULL;
    //push(&head, data1);
    //append(&head, data4);


    //increasingInsertion(&head, data3);
    
    descendingInsert(&head, data3);
    descendingInsert(&head, data4);
    descendingInsert(&head, data1);
    descendingInsert(&head, data2);


    showAllNodes(head);

   
    //struct Node *searched = search(&head, 7);
    
    //pop(&head, 7);
    
    destroyList(&head); 
    return 0;
}

/*
1 - verificar se a lista está vazia nas funções
*/