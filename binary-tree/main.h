#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "insertion.h"
#include "information.h"

struct Data {
    int intData;
    float floatData;
    char charData[20];
};

struct Node {
    struct Data data;
    struct Node *right;
    struct Node *left;
};

#endif