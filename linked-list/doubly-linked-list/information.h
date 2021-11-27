#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief verifica se a lista possui algum nó. Se a lista estiver vazia, retornar 1, se estiver com algum nó, retornar 0.
 * @param head_ref struct Node que aponta para o primeiro e último nó da lista encadead dupla
 */
int emptyList(struct Node **head_ref);

/**
 * @brief mostra todos os dados de todos os nós da lista encadead dupla
 * @param head_ref struct Node que aponta para o primeiro e último nó da lista encadeada dupla
 */
void showAllNodes(struct Node **head_ref);

#endif