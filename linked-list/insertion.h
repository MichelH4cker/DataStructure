#ifndef __INSERTION_H__
#define __INSERTION_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "createDestroyList.h"

struct Data;
struct Node;

/**
 * Insere no início da lista 
 */
int push(struct Node **head, struct Data inputData);

/**
 * Insere no final da lista
 */
int append(struct Node **head, struct Data inputData);

#endif

