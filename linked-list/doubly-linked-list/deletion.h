#ifndef __DELETION_H__
#define __DELETION_H__

#include "main.h"

struct Node;

/**
 * @brief deleta o primeiro nó da lista encadeada dupla
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void deleteFirst(struct Node **head_ref);

/**
 * @brief deleta o último nó da lista encadeada dupla
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void deleteLast(struct Node **head_ref);


/**
 * @brief deleta o nó de número int especificado nos parâmetros da função
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 * @param nodeNumber número do nó a ser excluído, se for três, por exemplo, será excluído o terceiro nó
 */
void deleteSpecific(struct Node **head_ref, int nodeNumber);

#endif