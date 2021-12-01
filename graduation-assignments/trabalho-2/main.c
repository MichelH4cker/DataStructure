/**
 * @file main.c
 * @author Michel Hecker Faria (michel.hecker@usp.br). nUSP: 12609690
 * @brief Este trabalho é relacionado ao uso de listas encadeadas dinâmicas (no meu caso, listas duplamente encadeadas) e que irá ser usada para armazenar os dados 3D em matrizes esparsas com dados ordenados e com consulta “rápida”, priorizando alguma das coordenadas. O programa também irá apresentar o desempenho na consulta aos dados destas diferentes listas com dados 3D esparsos. Serão criadas 5 listas encadeadas com os MESMOS dados nas 5 listas, o que vai permitir depois comparar o “custo” de acessar os dados. As 5 listas que serão criadas são:
   -1: Lista ordenada em X, depois em Y e depois em Z (em caso de empate> x -> y -> z)
   -2: Lista ordenada em Y, depois em X e depois em Z (em caso de empate> x -> y -> z)
   -3: Lista ordenada em Z, depois em X e depois em Y (em caso de empate> x -> y -> z)
   -4: Lista não ordenada com inserção no início
   -5: Lista não ordenada com inserção no final 
 * @version 0.1
 * @date 2021-12-14
 * @copyright Copyright (c) 2021
 */

#include "main.h"

void destroyList(struct Node **head_ref){
    struct Node *currentNode = *head_ref;
    struct Node *helperNode = *head_ref;

    while (currentNode != NULL){
        helperNode = currentNode->next;
        free(currentNode);
        currentNode = helperNode;
    }
    
    *head_ref = NULL;
}

int main () {
    struct Node *headNonOrderedPush = NULL;
    struct Node *headNonOrderedAppend = NULL;

    readAndStorageFile(&headNonOrderedPush, &headNonOrderedAppend);

    printf("inserção com push: \n");
    li(headNonOrderedPush);
    printf("====================== \n");
    printf("inserção com append: \n");
    lf(headNonOrderedAppend);

    destroyList(&headNonOrderedPush);
    destroyList(&headNonOrderedAppend);
    
    return 0;
}