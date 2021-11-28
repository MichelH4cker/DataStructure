#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief retorna a quantidade de nós que a lista encadeada dupla possui, ou seja, seu comprimento
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 * @return int - comprimento da lista 
 */
int len(struct Node *head_ref);

/**
 * @brief mostra todos os dados de todos os nós da lista encadead dupla
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void showAllNodes(struct Node *head_ref);

#endif