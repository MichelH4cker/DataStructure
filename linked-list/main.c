#include "main.h"

int main(){
    struct Data data1 = {1, "michel", 7.5};
    List *head = createList();
    
    pushFront(head, data1);

    destroyList(head);
    return 0;
}