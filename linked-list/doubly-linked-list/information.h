#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief mostra todos os dados de todos os nós da lista encadead dupla
 * @param head_ref struct Node que aponta para o primeiro e último nó da lista encadeada dupla
 */
void showAllNodes(struct Node *head_ref);

#endif