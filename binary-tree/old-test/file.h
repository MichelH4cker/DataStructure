#ifndef __FILE_H__
#define __FILE_H__

#include "main.h"

struct Node;
struct Data;

/** 
 * @brief lẽ o arquivo "dados.txt" e armazena nas árovres pedidas
 * @param cpfTree ponteiro para a raiz da árvore cpf
 * @param nRegTree ponteiro para a raiz da árvore nReg
 */
void readAndStorageFile(struct Node **cpfTree, struct Node **nRegTree);

/**
 * @brief escreve os dados contidos na árvore nos arquivos "CPF.txt" e "NReg.txt". A escolha dos arquivos depende da flag passada como parâmetro
 * 
 * @param root_ref ponteiro para a raiz da árvore
 * @param fp ponteiro para arquivo
 */
void fprintfInFile(struct Node **root_ref, FILE **fp);

/**
 * @brief verifica qual arquivo deve ser aberto e chama a função readAndStorageInFile
 * 
 * @param root_ref ponteiro para a raiz da árvore
 * @param flag 0 para cpf e 1 para nreg 
 */
void createAndStorageInFile(struct Node **root_ref, int flag);

/**
 * @brief lê o arquivo criado e mostra os dados contidos nele
 * 
 * @param flag 0 para cpf e 1 para nreg 
 */
void readCreatedFiles(int flag);

#endif