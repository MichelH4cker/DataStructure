#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "insertion.h"
#include "information.h"
#include "removal.h"

struct Data {
    int dataInteger;
    char dataString[30];
    float dataFloat;
};

struct Node {
    struct Data data;
    struct Node *next;
};

#endif