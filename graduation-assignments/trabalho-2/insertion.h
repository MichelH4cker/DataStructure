#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief 
 * @param
 */
int switchAxis(int axis, int currentAxis);

/**
 * @brief 
 * @param
 */
void hierarchyOfAxis(struct Node **newNode_ref, struct Node **currentNode_ref, int mainAxis, int currentAxis);

/**
 * @brief Insere dados no início da lista encadeada dupla
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @param data struct Data que contém os dados a serem inseridos na lista
 */
void push(struct Node **head_ref, struct Data data);

/**
 * @brief Insere dados no final da lista encadeada dupla 
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @param data struct Data que contém os dados a serem inseridos na lista
 */
void append(struct Node **head_ref, struct Data data);

/**
 * @brief Insere dados de forma ordenada (ordem crescente)
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @param data struct Data que contém os dados a serem inseridos na lista
 */
void sortedInsert(struct Node **head_ref, struct Data data, int mainAxis);

#endif