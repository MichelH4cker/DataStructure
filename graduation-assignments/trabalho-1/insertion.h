#ifndef __INSERTION_H__
#define __INSERTION_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

struct Node;

/**
 * Insere de maneira decrescente
 * @param head_ref primeiro nó da lista
 * @param inputData valor a ser inserido na lista
 */
void descendingInsert(struct Node **head_ref, float inputData);

/**
 * Insere de maneira crescente
 * @param head_ref primeiro nó da lista
 * @param inputData valor a ser inserido na lista
 */ 
void crescentInsert(struct Node **head_ref, float inputData);


#endif