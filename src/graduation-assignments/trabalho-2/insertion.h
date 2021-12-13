#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief troca de eixo conforme a hierarquia. Dado o eixo principal e o eixo atual, a função muda o eixo atual e retorna o próximo eixo (critério)
 * @param axis eixo principal
 * @param currentAxis eixo atual
 * @return retorna o próximo eixo (critério)
 */
int switchAxis(int axis, int currentAxis);

/**
 * @brief insere de forma ordenada, levando em consideração o segundo e terceiro critério de inserção. Função recursiva
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @param newNode_ref ponteiro que aponta para o nó que será adicionado
 * @param mainAxis eixo principal
 * @param currentAxis eixo atual
 */
void hierarchyOfAxis(struct Node **head_ref, struct Node **newNode_ref, int mainAxis, int currentAxis);

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
void sortedInsert(struct Node **head_ref, struct Data data, int mainAxis, int currentAxis);

#endif