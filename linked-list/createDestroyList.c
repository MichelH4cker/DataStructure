#include "main.h"
#include "createDestroyList.h"

struct Node* createList(){
    struct Node* headList = malloc(sizeof(struct Node));

    if (headList != NULL){
        headList = NULL;
        return headList;
    }
    
}

void destroyList(struct Node *head){
    struct Node* node;

    while (head != NULL){
       node = head;
       head = head->next;
       free(node);
    }
    free(node);
}