#ifndef __FILE_H__
#define __FILE_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief lê o arquivo "cepdata.txt", armazenando todos os dados em uma árvore binária do tipo AVL
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 */
void readAndStorageFile(struct Node **root_ref);


#endif