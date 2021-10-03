#include "main.h"
#include "createDestroyList.h"

List* createList(){
    List *li = malloc(sizeof(List));
    if (li != NULL){
        *li = NULL;
        return li;
    }
    
}

void destroyList(List *li){
    free(li);
}