#ifndef __CREATEDESTROY_H__
#define __CREATEDESTROY_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"

typedef struct Node* List;

List* createList();

/**
 * 
 * Destroy memory allocated 
 * destroy pointer head
 * destroy all nodes until null
 */
void destroyList(List *li);

#endif