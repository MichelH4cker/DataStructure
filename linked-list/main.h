#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "insertion.h"

struct Data {
    int dataInteger;
    char dataString[30];
    float dataFloat;
};

typedef struct {
    struct Node *next;
    struct Data data;
} Node;


typedef struct Node* List;

#endif