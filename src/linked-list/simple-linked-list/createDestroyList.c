#include "main.h"
#include "createDestroyList.h"

struct Node* createList(){
    struct Node* headList = malloc(sizeof(struct Node));

    if (headList != NULL){
        headList = NULL;
        return headList;
    }
    
}

//**head = struct Node
void destroyList(struct Node **head){
    struct Node *currentNode = *head;
    struct Node *nextNode;
    while (currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;

    }
    *head = NULL;
    
}


/*
struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
*/