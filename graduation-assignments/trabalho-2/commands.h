#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

struct RGB;
struct Coordinate;
struct Data;
struct Node;

/**
 * @brief Lista todos os nós da lista passada como parâmetro
 * @param head_ref Nó cabeçalho da lista, ou seja, priemiro nó da lista encadeada dupla
 */
void showAllNodes(struct Node **head_ref);

/**
 * @brief Listar todos dados da lista ordenada por X (X depois Y depois Z) 
 * @param head_ref Nó cabeçalho da lista, ou seja, primeiro nó da lista encadead dupla
 */
void lx(struct Node *head_ref);

/**
 * @brief Listar todos dados da lista ordenada por Y (Y depois X depois Z)
 * @param head_ref Nó cabeçalho da lista, ou seja, primeiro nó da lista encadeada dupla
 */
void ly(struct Node *head_ref);

/**
 * @brief Listar todos dados da lista ordenada por Z (Z depois X depois Y)
 * @param head_ref Nó cabeçalho da lista, ou seja, primeiro nó da lista encadeada dupla
 */
void lz(struct Node *head_ref);

/**
 * @brief Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no início da lista
 * @param head_ref Nó cabeçalho da lista, ou seja, o primeiro nó da lista encadeada dupla
 */
void li(struct Node *head_ref);

/**
 * @brief Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no final da lista
 * @param head_ref Nó cabeçalho da lista, ou seja, o primeiro nó da lista encadeada dupla
 */
void lf(struct Node *head_ref);

/**
 * @brief Exibir o total de nodos acessados nas inserções nas listas LX,LI,LF
 * @param head_ref Nó cabeçalho da lista, ou seja, o primeiro nó da lista encadeada dupla
 * @return int soma das quantidades de vezes em que os nodos foram acessados
 */
int tot(struct Node **head_ref);

/**
 * @brief Listar o dado mais próximo em Z contido na lista ordenada por Z, ou seja, mostrar o dado com o menor valor de Z e o total de nodos visitados para achar este dado
 * @param
 */
void pz();

/**
 * @brief Listar o dado mais próximo em Z, contido na lista não ordenada com inserção no Início, ou seja, mostrar o dado com o menor valor de Z e o total de nodos visitados para achar este dado
 * @param
 */
void pi();

/**
 * @brief Ler do teclado um número inteiro representando o ID procurado e exibir apenas os dados que possuem o ID informado. Exibir no formato igual ao das opões LX,LY,LZ,LI e LF, porém aplicando  um  filtro  que exibe apenas os dados com o ID solicitado. Consultar a lista ordenada por X (LX – X depois Y depois Z) para exibir os dados
 * @param
 */
void id();

/**
 * @brief  Ler do teclado 3 números com as coordenadas X,Y,Z mínimas e 3 números com as coordenadas X,Y,Z máximas, definindo um “bounding box" (retângulo de recorte) dos dados 3D. Considerando a lista LX (ordem em X depois Y e depois Z, exibir na tela apenas os dados que ficam dentro do retângulo definido (incluindo os limites max e min)
 * @param
 */
void cut();

#endif