#ifndef __CREATEDESTROY_H__
#define __CREATEDESTROY_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

struct Node;

/**
 * Desalocação de memória 
 * de toda lista
 * @param head_ref primeiro nó da lista
 */ 
void destroyList(struct Node **head_ref);


#endif
