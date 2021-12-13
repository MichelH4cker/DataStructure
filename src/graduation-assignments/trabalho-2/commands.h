#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "main.h"

struct RGB;
struct Coordinate;
struct Data;
struct Node;

/**
 * @brief Percorre um array que contém todos os comandos necessários para exceução do programa. Ao encontrar o comando digitado pelo usuário, retorna a posição do mesmo, equivalente à key do comando
 * @return int key, código correspondente ao comando
 */

int idOfCommand();

/**
 * @brief 
 * @param
 */
void wallyActs();

/**
 * @brief Lista todos os nós da lista passada como parâmetro
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @param id variável que guarda o valor do id pedido para printar (se necessário)
 * @param idFunctionActivated variável booleana pra sinalizar se a função muda seu comportamento ou não
 */
void showAllNodes(struct Node **head_ref, int id, int idFunctionActivated);

/**
 * @brief Listar todos dados da lista ordenada por X (X depois Y depois Z) 
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void lx(struct Node **head_ref);

/**
 * @brief Listar todos dados da lista ordenada por Y (Y depois X depois Z)
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void ly(struct Node **head_ref);

/**
 * @brief Listar todos dados da lista ordenada por Z (Z depois X depois Y)
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void lz(struct Node **head_ref);

/**
 * @brief Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no início da lista
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void li(struct Node **head_ref);

/**
 * @brief Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no final da lista
 * @param head_ref ponteiro para o início da lista encadeada dupla
 */
void lf(struct Node **head_ref);

/**
 * @brief soma todos as variáveis int que guardam a quantidade de nós acessados, chegando no total de nós acessados
 * @param head_ref ponteiro para o início da lista encadeada dupla
 * @return retona quantidade de nós acessados
 */
int addIntAccessedNodes(struct Node **head_ref);

/**
 * @brief Exibir o total de nodos acessados nas inserções nas listas LX,LI,LF
 * @param headOrdered_ref ponteiro para o início da lista encadeada dupla ordenada no eixo pedido
 * @param headPush_ref ponteiro para o ínicio da lista encadeada dupla, onde os dados foram inseridos sempre no início
 * @param headAppend_ref ponteiro para o ínicio da lista encadeada dupla, onde os dados foram inseridos sempre no final
 */
void tot(struct Node **headOrdered_ref, struct Node **headPush_ref, struct Node **headAppend_ref);

/**
 * @brief Listar o dado mais próximo em Z contido na lista ordenada por Z, ou seja, mostrar o dado com o menor valor de Z e o total de nodos visitados para achar este dado
 * @param head_ref ponteiro para o ínicio da lista encadeada dupla
 */
void pz(struct Node **head_ref);

/**
 * @brief Listar o dado mais próximo em Z, contido na lista não ordenada com inserção no Início, ou seja, mostrar o dado com o menor valor de Z e o total de nodos visitados para achar este dado
 * @param head_ref ponteiro para o ínicio da lista encadeada dupla
 */
void pi(struct Node **head_ref);

/**
 * @brief Ler do teclado um número inteiro representando o ID procurado e exibir apenas os dados que possuem o ID informado. Exibir no formato igual ao das opões LX,LY,LZ,LI e LF, porém aplicando  um  filtro  que exibe apenas os dados com o ID solicitado. Consultar a lista ordenada por X (LX – X depois Y depois Z) para exibir os dados
 * @param head_ref ponteiro para o ínicio da lista encadaeada dupla
 * @param id inteiro equivalente ao id pedido pelo usuário
 */
void id(struct Node **head_ref, int id);

/**
 * @brief  Ler do teclado 3 números com as coordenadas X,Y,Z mínimas e 3 números com as coordenadas X,Y,Z máximas, definindo um “bounding box" (retângulo de recorte) dos dados 3D. Considerando a lista LX (ordem em X depois Y e depois Z, exibir na tela apenas os dados que ficam dentro do retângulo definido (incluindo os limites max e min)
 * @param head_ref ponteiro para o ínicio da lista encadeada dupla
 * @param coordinateMax array que guarda a coordenada (x,y,z) do limite máximo
 * @param coordinateMin array que guarda a coordenada (x,y,z) do limite mínimo
 */
void cut(struct Node **head_ref, float *coordinateMax, float *coordinateMin);

#endif