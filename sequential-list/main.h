#ifndef __MAIN_H__
#define __MAIN_H__

#define MAX_LIST 100 //tamanho máximo do vetor

struct Data {
    int dataInteger;
    char dataString[30];
    float dataFloat;
};


typedef struct {
    int occupiedPositions;
    struct Data list[MAX_LIST];
} List;

#endif