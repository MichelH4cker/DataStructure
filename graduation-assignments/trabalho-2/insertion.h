#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief Insere dados no início da lista encadeada dupla
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void push(struct Node **head_ref, struct Data data);

/**
 * @brief Insere dados no final da lista encadeada dupla 
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void append(struct Node **head_ref, struct Data data);

#endif