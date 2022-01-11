#ifndef __FILE_H__
#define __FILE_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief lê os dados contidos no arquivo "circuit.txt", adicionando-os a árvore binária
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 */
void readAndStoreFile (struct Node **root_ref);

#endif