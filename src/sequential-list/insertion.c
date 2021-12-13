#include "insertion.h"

#include <stdio.h>
#include <stdlib.h>

int error(List *list){
    if (list == NULL || list->occupiedPositions == MAX_LIST){
        printf("algo de errado não está certo! melhor começar tudo de novo! \n");
        return 1;
    } 
    return 0;
}

int startInsertion(List *list, struct Data content){
    if (error(list) == 1) {
        return 0;
    } 
    
    for (int i = 0; i < list->occupiedPositions; i++){
        list->list[i + 1] = list->list[i];
        
    }

    list->list[0] = content;
    list->occupiedPositions++;
    printf("inserido com sucesso! \n");
    printf("\n");

    return 1;
}

int endInsertion(List *list, struct Data content){
    if (error(list) == 1){
        return 0;
    }
    
    list->list[list->occupiedPositions] = content;
    list->occupiedPositions++;

    return 1;
}

int specificInsertion(List *list, struct Data content){
    if (error){ 
        return 0;
    }
}


