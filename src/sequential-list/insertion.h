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

int startInsertion(List *list, struct Data content);

int endInsertion(List *list, struct Data content);

int specificInsertion(List *list, struct Data content);



#endif