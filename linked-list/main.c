#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    struct Data data2 = {3, "amanda", 7.5};
    struct Data data3 = {7, "append", 2.5};
    struct Data data4 = {5, "ordenada", 3.14};
    //struct Node *head = createList(); // pointer to pointer
    struct Node *head = NULL;
    //push(&head, data1);
    //push(&head, data2);
    //push(&head, data3);
    //append(&head, data4);

    //increasingInsertion(&head, data3);
    //increasingInsertion(&head, data1);
    //increasingInsertion(&head, data2);
    //increasingInsertion(&head, data4);

    showAllNodes(head);
    //int lenList = len(head);

    //removeLastNode(&head);
    //removeFirstNode(&head);
   
    //struct Node *searched = search(&head, 7);
    
    //pop(&head, 7);
    
    destroyList(&head); 
    return 0;
}

/*
1 - verificar se a lista está vazia nas funções
*/