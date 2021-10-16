#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

struct Node* createList(){
    struct Node *li;
    li = malloc(sizeof(struct Node));
    if (li != NULL){
        li = NULL; 
    }
    return li;
}

void destroyList(){

}

void freeList(struct Node *list){
    free(list);
}