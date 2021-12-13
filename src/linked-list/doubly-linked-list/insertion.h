#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief insere dados do tipo Data (struct) 
 * no início da lista encadeada dupla
 * @param data struct Data com dados integer, char e float
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void push(struct Data data, struct Node **head_ref);

/**
 * @brief insere dados do tipo Data (struct) no fim da lista encadeada dupla
 * @param data struct Data com dados integer, char e float
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void append(struct Data data, struct Node **head_ref);

/**
 * @brief insere dados do tipo Data (struct) no fim da lista encadeada dupla. Observação importante: essa função está ordenando os dados por meio dos valores dos tipos inteiros
 * @param data struct Data com dados integer, char e float
 * @param head_ref struct Node que aponta para o primeiro nó da lista encadeada dupla
 */
void sortedInsert(struct Data data, struct Node **head_ref);

#endif