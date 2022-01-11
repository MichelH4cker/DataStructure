/**
 * @name L-GRoot : Logical Gate Root. O nome foi inspirado no herói da marvel (Groot). a pronúncia é #éli gruti#. 
 * @author Michel Hecker Faria - 12609690
 * @brief lê um arquivo que contém nodos. cada linha do arquivo possui um nodo filho que será inserido numa árvore binária, a direção que será inserido a partir do pai e o nodo pai. a árvore binária criada correspondente a um circuito digital, onde os nodos folhas receberão uma entrada (0 ou 1) e o programa fará o tratamento dessas entradas por meio da lógica digital contida no circuito (ou seja, na árvore binária), devolvendo a saída (0 ou 1).
 * @version 0.1
 * @date 2022-01-13
 * @copyright Copyright (c) 2022
 **/
#include "main.h"

int main (){
    struct Node *root = NULL;

    readAndStoreFile(&root);
    
    checkForLeafNodes(root);    

    int total = totalLeafNodes(root);
    
    receiveInputLeafNodes(root, total);

    LGRootSolvesCircuit(root);
    printf("%d\n", root->data.inputValue);

    freeLGRoot(root);

    return 0;
}