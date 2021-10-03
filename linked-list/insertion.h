#ifndef __INSERTION_H__
#define __INSERTION_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "createDestroyList.h"

struct Data;

/**
 * Insere no início da lista 
 */
int pushHome(List *li, struct Data inputData);

void pop();

#endif

