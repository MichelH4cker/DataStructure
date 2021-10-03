#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    struct Node *head = createList();
    
    push(&head, data1);

    showAllNodes(head);

    destroyList(head);
    return 0;
}