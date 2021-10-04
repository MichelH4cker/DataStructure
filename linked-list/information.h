#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "createDestroyList.h"
#include "insertion.h"

/**
 * Função de output
 * mostra o conteúdo de todos os nós
 */
void showAllNodes(struct Node *head);

/**
 * Retorna a quantidade de nós
 */ 
int len(struct Node *head);

#endif