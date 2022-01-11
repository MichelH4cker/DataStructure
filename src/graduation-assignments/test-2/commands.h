#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief dado o inteiro digitado pelo usuário, esta função seleciona qual a função correspondente, executando-a
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 * @param id inteiro que corresponde à tarefa que o usuário deseja
 */
void remoteController(struct Node **root_ref, int id);

#endif