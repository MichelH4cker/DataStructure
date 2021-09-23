#ifndef __INSERTION_H__
#define __INSERTION_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "createDestroyList.h"


/**
 * Retorna se o ponteiro para 
 * a variável list está vazio
 */
int error(List *list);

int fullList(List *list);

void startInsertion(List *list, struct Data content);

int endInsertion(List *list);

int specificInsertion(List *list);



#endif