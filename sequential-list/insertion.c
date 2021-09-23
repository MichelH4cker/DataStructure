#include "insertion.h"

#include <stdio.h>
#include <stdlib.h>


int error(List *list){
    if (list == NULL || list->occupiedPositions == MAX_LIST){
        return 1;
    } 
    return 0;
}

void startInsertion(List *list, struct Data contentX){
    if (error(list) == 1) {
        printf("algo de errado não está certo, melhor começar tudo de novo! \n");
    } 
    
    for (int i = 0; i < list->occupiedPositions; i++){
        list->list[i + 1] = list->list[i];
        printf("%d \n", list->list[1].dataInteger);
    }

    list->list[0] = contentX;
    list->occupiedPositions++;
    printf("inserido com sucesso! \n");

    
}

int endInsertion(List *list){
    if (error){
        return (-1);
    }
}

int specificInsertion(List *list){
    if (error){ 
        return (-1);
    }
}


