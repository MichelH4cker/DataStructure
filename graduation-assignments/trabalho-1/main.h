#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"
#include "insertion.h"

struct Node {
    float data;         // dado
    struct Node *next;  // ponteiro para próximo nó
};


/**
 * Verifica se pelo menos um número
 * da lista é float. 
 * Retorna 1 se tiver pelo menos um float.
 * Retorna 0 se não tiver um pelo menos um float.
 * @param head_ref primeiro nó da lista
 */ 
int itsFloat(struct Node *head_ref);

/**
 * Output:
 * mostra todos os dados dentro dos nós
 * @param head_ref primeiro nó da lista
 * @param isFloat
 */ 
void showAllNodes(struct Node *head_ref, int isFloat);

/**
 * Lê diversos valores, inserindo-os
 * na lista encadeada simples. 
 * Quando o número 0 é digitado,
 * a função acaba
 * @param head primeiro nó da lista
 * @param typeInsertion tipo da inserção que o usuário fará
 */ 
void receiveInputs(struct Node **head, int typeInsertion);

#endif