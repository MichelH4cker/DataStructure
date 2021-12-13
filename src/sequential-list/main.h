#ifndef __MAIN_H__
#define __MAIN_H__

#define MAX_LIST 10 //tamanho máximo do vetor

#include <stdio.h>
#include <stdlib.h>

struct Data {
    int dataInteger;
    char dataString[30];
};


typedef struct {
    int occupiedPositions;
    struct Data list[MAX_LIST];
} List;

#endif