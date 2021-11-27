#ifndef __REMOVAL_H__
#define __REMOVAL_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "createDestroyList.h"
#include "insertion.h"
#include "information.h"

/**
 * Remove o primeiro nó da lista
 */
void removeFirstNode(struct Node **head);


/**
 * Remove o último nó da lista
 */
void removeLastNode(struct Node **head);

/**
 * Remove o nó especificado da lista
 */
void pop(struct Node **head, int key);

#endif