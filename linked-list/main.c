#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    struct Data data2 = {3, "amanda", 7.5};
    struct Data data3 = {7, "append", 2.5};
    struct Data data4 = {5, "ordenada", 3.14};
    struct Node *head = createList();
    
    push(&head, data1);
    push(&head, data2);
    append(&head, data3);
    //sortedInsert(&head, data1);
    
    showAllNodes(head);
    //int lenList = len(head);

    removeLastNode(&head);
    showAllNodes(head);

    destroyList(head);
    return 0;
}