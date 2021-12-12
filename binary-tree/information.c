#include "information.h"

void showAllNodes(struct Node* root_ref){
    if (root_ref != NULL){
        showAllNodes(root_ref->left);
        printf("%d %f %s\n", root_ref->data.intData, root_ref->data.floatData, root_ref->data.charData);
        showAllNodes(root_ref->right);
    }
}

int totalNodes(struct Node *node){
    if (node == NULL)
        return 0;
    if (*node == NULL)
        return 0;
    int leftHeight = totalNodes(&((*node).left));
    int rightHeight = totalNodes(&((*node).right));
    return(leftHeight + rightHeight + 1);
}
