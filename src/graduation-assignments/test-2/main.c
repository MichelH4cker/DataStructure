/**
 * @file main.c
 * @author Michel Hecker Faria - NUSP: 12609690
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main.h"

int main(){
    struct Node *root =NULL;
    
    readAndStorageFile(&root);
    
    int id;
    scanf("%d", &id);

    remoteController(&root, id);
    
    freeTree(root);

    return 0;
}
