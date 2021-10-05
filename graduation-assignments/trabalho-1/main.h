#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

typedef struct {
    struct Node *PointerToNext;
    float data;
} Node;

#endif