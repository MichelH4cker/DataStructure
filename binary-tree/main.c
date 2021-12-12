#include "main.h"

void freeNode(struct Node* node){
    if(node == NULL) return;

    freeNode(node->left);
    freeNode(node->right);
    
    free(node);
    node = NULL;
}

void freeTree(struct Node* root){
    if(root == NULL) return;
    
    freeNode(*root);
    free(root);
}

int main (){
    struct Node *root;

    struct Data newData1;
    newData1.intData = 0;
    newData1.floatData = 0.0;
    strcpy(newData1.charData, "alguma coisa");

    root = insert(root, newData1);
    showAllNodes(root);
    return 0;
}