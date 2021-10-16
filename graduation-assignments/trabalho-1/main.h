#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"
#include "insertion.h"

struct Node {
    float data;
    struct Node *next;
};


/**
 * 
 * 
 * 
 */ 
int receiveInputs(struct Node *array, int totalInputs);

/**
 * 
 * 
 */ 
void showAllNodes(struct Node *array, int totalInputs);

#endif