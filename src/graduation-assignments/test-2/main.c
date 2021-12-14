#include "main.h"

int main(){
    struct Node *root =NULL;
    
    readAndStorageFile(&root);
    
    int id;
    printf("Digita: ");
    scanf("%d", &id);

    remoteController(&root, id);
    
    freeTree(root);

    return 0;
}
