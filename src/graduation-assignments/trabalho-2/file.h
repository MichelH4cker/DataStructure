#ifndef __FILE_H__
#define __FILE_H__

#include "main.h"

struct Node;

/**
 * @brief lê os dados do arquivo e armazena, por meio da função push, em uma lista encadeada dupla
 * @param headOrderedX_ref cabeçalho de uma lista ordenada pelo critério em X
 * @param headOrderedY_ref cabeçalho de uma lista ordenada pelo critério em Y
 * @param headOrderedZ_ref cabeçalho de uma lista ordenada pelo critério em Z
 * @param headPush_ref cabeçalho de uma lista não ordenada onde os dados foram inseridos sempre no ínicio
 * @param headAppend_ref cabeçalho de uma lista não ordenada onde os dados foram inseridos sempre no final
 */
void readAndStorageFile(struct Node **headOrderedX_ref, struct Node **headOrderedY_ref, struct Node **headOrderedZ_ref, struct Node **headPush_ref, struct Node **headAppend_ref);

#endif