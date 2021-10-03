#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    struct Data data2 = {2, "amanda", 7.5};
    struct Data data3 = {3, "append", 2.5};
    struct Node *head = createList();
    
    push(&head, data1);
    push(&head, data2);
    append(&head, data3);

    showAllNodes(head);

    destroyList(head);
    return 0;
}