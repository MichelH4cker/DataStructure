#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

List* createList(){
    List *li;
    li = malloc(sizeof(*List));
    if (li != NULL){
        *li = NULL; 
    }
    return li;
}

void destroyList(){

}

void freeList(List *list){
    free(list);
}