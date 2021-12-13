#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

struct Search;
struct Node;


/**
 * Adiciona nó ao final da lista
 */ 
void append(struct Node **head_ref, struct Search data);    

struct Node* searchAndPop(struct Node **head, char *prefix);

void pop(struct Node **head, char *prefix);


#endif