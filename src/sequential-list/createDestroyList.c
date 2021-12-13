#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"

List* createList(){
    List *list;

    list = malloc(sizeof(List));
    
    if (list != NULL){
        list->occupiedPositions = 0;
        return list;
    }
}

void freeList(List *list){
    free(list);

}