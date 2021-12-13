#include "information.h"
 
void order(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        order(&((*root_ref)->left));
        printf("Dados: %d (CPF) - %d (NREG)\n", (*root_ref)->data.dataArray[CPF], (*root_ref)->data.dataArray[NREG]);
        order(&((*root_ref)->right));
    }
}
