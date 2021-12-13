#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;


/**
 * @brief create a New Node struct
 * 
 * @param newData struct Data para inserir no nó 
 * @return struct Node* 
 */
struct Node* createNewNode(struct Data newData);

/**
 * @brief insere de maneira ordenada na árvore binária
 * 
 * @param root_ref ponteiro para a raiz da árvore
 * @param newData struct Data para inserir no nó
 * @param flag 0 para cpf e 1 para nreg 
 */
void insert(struct Node **root_ref, struct Data newData, int flag);

#endif