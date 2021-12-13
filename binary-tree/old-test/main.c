#include "main.h"

void freeTree(struct Node* node){
    if(node == NULL) return;

    freeTree(node->left);
    freeTree(node->right);
    
    free(node);
    node = NULL;
}

int main (){
    struct Node *cpfTree  = NULL;
    struct Node *nRegTree = NULL;

    readAndStorageFile(&cpfTree, &nRegTree);

    printf("\n===============================\n");
    printf("INÍCIO DA LEITURA DO ARQUIVO DADO\n");
    printf("===============================\n");

    printf("Dados CPF:\n");
    order(&cpfTree);
    printf("===============================\n");
    printf("Dados NREG:\n");
    order(&nRegTree);

    createAndStorageInFile(&cpfTree, CPF);
    createAndStorageInFile(&nRegTree, NREG);

    printf("\n===============================\n");
    printf("INÍCIO DA LEITURA DOS ARQUIVOS CRIADOS\n");
    printf("===============================\n");

    printf("Lendo o arquivo CPF.txt\n");
    readCreatedFiles(CPF);
    printf("===============================\n");

    printf("Lendo o arquivo NReg.txt\n");
    readCreatedFiles(NREG);
    printf("===============================\n");

    freeTree(cpfTree);
    freeTree(nRegTree);

    return 0;
}