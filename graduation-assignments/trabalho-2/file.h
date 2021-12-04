#ifndef __FILE_H__
#define __FILE_H__

#include "main.h"

struct Node;

/**
 * @brief retorna o número correspondente ao eixo a ser trabalhado. Número 0, 1 e 2, são os eixos x, y e z, respectivamente
 * @return int correspondente ao eixo 
 */
int whichAxis();

/**
 * @brief lê os dados do arquivo e armazena, por meio da função push, em uma lista encadeada dupla
 * @param headNonOrdered cabeçalho de uma lista não ordenada. Como a lista é encadeada dupla, iserir no início ou inserir no final não faz tanta diferença 
 */
void readAndStorageFile(struct Node **headNonOrderedPush_ref, struct Node **headNonOrderedAppend_ref, struct Node **headOrdered_ref, int mainAxis);

#endif