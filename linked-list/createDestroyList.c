#include "main.h"
#include "createDestroyList.h"

struct Node* createList(){
    struct Node* li = malloc(sizeof(struct Node));

    if (li != NULL){
        li = NULL;
        return li;
    }
    
}

void destroyList(struct Node *li){
    free(li);
}