#ifndef __TREE_H__
#define __TREE_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief Desaloca todos os nodos da árvore binária
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária 
 */
void freeLGRoot(struct Node *root_ref);

/**
 * @brief recebe uma variável char que contém a identificação padrão do nodo. com isso, a identificação padrão é associada a algum número de 0 a 5. tal número é guardado numa variável conntida no nodo, sendo útil posteriormente (na parte de lógica)
 * @param uniqueIdentifier 
 * @return int 
 */
int identifiesNodeType(char *uniqueIdentifier);

/**
 * @brief retorna um inteiro, correspondente ao total de nodos folhas contidos na árvore binária
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 * @return int guarda o total de nodos folhas que a árvore binária possui
 */
int totalLeafNodes(struct Node *root_ref);

/**
 * @brief dada a identificação do nodo folha (charInput) e sua entrada (intInput), essa função buscará o nodo que contém essa informação e inserirá sua entrada. caso nenhum nodo com tal especificação seja encontrado, mostrará uma mensagem de erro e o programa será encerrado
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 * @param charInput 
 * @param intInput 
 */
void searchAndInsertInput(struct Node *root_ref, char *charInput, int intInput);


/**
 * @brief lê a identificação do nodo folha e qual sua entrada (1 ou 0)
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 */
void receiveInputLeafNodes(struct Node *root_ref, int amountOfLeafNodes);

/**
 * @brief busca os nodos folhas da árvore e verifica se todos os nodos folhas possuem a identificação INP. caso a função encontre nodos folhas que não possuem a identificação INP, mostrará uma mensagem de erro e o programa será encerrado
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 */
void checkForLeafNodes(struct Node *root_ref);

/**
 * @brief dá continuidade a função insert, porém está é uma função responsiva,, onde finalmente o novo nodo é inserido 
 * @param currentNode_ref nodo atual
 * @param newNode_ref novo nodo
 * @param newData struct do tipo Data que contém todos os dados a serem inseridos no nodo
 * @param direction qual direção (left or right) o novo nodo deverá ser inserido logo abaixo de seu nodo pai
 * @param fatherReference identifcação em string do nodo pai, utilizado como busca
 * @param inserted variável flag responsável por guardar a informação se o nodo foi inserido (1) ou não (0)
 */
void insertOperation (struct Node *currentNode_ref, struct Node *newNode_ref, struct Data newData, char direction, char fatherReference[6], int *inserted);

/**
 * @brief insere os dados do tipo Data em um novo nodo, que por sua vez é inserido na esquerda ou na direita de seu nodo pai (as informações acerca da direção, bem como qual é o nodo pai estão todas contidas no arquivo "circuit.txt"). caso o nodo pai não seja encontrado ou haja a tentativa de inserir uma informação diferente em um memso nodo, haverá uma mensagem de erro e o programa será encerrado
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 * @param newData struct do tipo Data que contém todos os dados a serem inseridos no nodo
 * @param direction qual direção (left or right) o novo nodo deverá ser inserido logo abaixo de seu nodo pai
 * @param fatherReference identifcação em string do nodo pai, utilizado como busca
 */
void insert (struct Node** root_ref, struct Data newData, char direction, char fatherReference[6]);

/**
 * @brief lê as entradas contidas nos nodos folhas e calcula as operações lógicas do circuito 
 * @param root_ref ponteiro do tipo Node que aponta para a raiz da árvore binária
 * @return int útil para a continuidade das operações lógicas do circuito  
 */
int LGRootSolvesCircuit(struct Node *root_ref);

#endif