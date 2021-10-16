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
void receiveInputs(struct Node **head, int typeInsertion);

/**
 * Output:
 * mostra todos os dados dentro dos nós
 * @param head_ref
 * @param isFloat
 */ 
void showAllNodes(struct Node *head_ref, int isFloat);

/**
 * 
 * 
 * 
 */ 
int itsFloat(struct Node *head_ref);

#endif