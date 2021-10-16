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
struct Node* receiveInputs(struct Node **head);

/**
 * 
 * 
 */ 
void showAllNodes(struct Node **array, int totalInputs);

#endif