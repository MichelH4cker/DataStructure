#ifndef __TREETAD_H__
#define __TREETAD_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief desaloca a memória de todos os nós da árvore binária AVL
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 */
void freeTree(struct Node *root_ref);

/**
 * @brief insere os dados contidos na struct Data na árvore binária AVL
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 * @param newData 
 * @return int 
 */
int insert(struct Node **root_ref, struct Data newData);

/**
 * @brief retorna como inteiro a altura da árvore binária AVL
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore bináriastruct Node que aponta para a raiz da árvore binária
 * @return int 
 */
int heightTree(struct Node **root_ref);

/**
 * @brief retorna como inteiro a quantidade total de nós inseridos na árvore binária AVL
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 * @return int 
 */
int totalNodes(struct Node **root_ref);

/**
 * @brief procura pela árvore binária AVL um nó que contenha o cep dado entre o cep incial do nó e o cep final do mesmo nó
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 * @param cep cep buscado na árvore binária AVL
 * @return int 
 */
struct Node* searchByCEP(struct Node **root_ref, int cep);

/**
 * @brief mostra todos os nós da árvore binária AVL da maneira pré ordem
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 */
void preOrder(struct Node **root_ref);

/**
 * @brief mostra todos os nós da árvore binária AVL da maneira em ordem
 * 
 * @param root_ref struct Node que aponta para a raiz da árvore binária
 */
void order(struct Node **root_ref);

#endif