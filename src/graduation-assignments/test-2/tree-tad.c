#include "tree-tad.h" //inclui os Prot�tipos

void freeTree(struct Node* node){
    if(node == NULL) return;

    freeTree(node->left);
    freeTree(node->right);
    
    free(node);
    node = NULL;
}

int heightNode(struct Node* Node){
    if(Node == NULL)
        return -1;
    else
    return Node->height;
}

int balancingTree(struct Node* Node){
    return labs(heightNode(Node->left) - heightNode(Node->right));
}

int bigger(int x, int y){
    if(x > y){
        return x;
    } else{
        return y;
    }
}

int totalNodes(struct Node **root_ref){
    if (root_ref == NULL)
        return 0;
    if (*root_ref == NULL)
        return 0;
    int alt_left = totalNodes(&((*root_ref)->left));
    int alt_right = totalNodes(&((*root_ref)->right));
    return(alt_left + alt_right + 1);
}

int heightTree(struct Node **root_ref){
    if (root_ref == NULL)
        return 0;
    if (*root_ref == NULL)
        return 0;
    int alt_left = heightTree(&((*root_ref)->left));
    int alt_right = heightTree(&((*root_ref)->right));
    if (alt_left > alt_right)
        return (alt_left + 1);
    else
        return(alt_right + 1);
}

void preOrder(struct Node **root_ref){
    if(root_ref == NULL) return;

    if(*root_ref != NULL){
        printf("%d %d %s %s\n",(*root_ref)->data.initialCEP, (*root_ref)->data.endCEP, (*root_ref)->data.city, (*root_ref)->data.state);
        preOrder(&((*root_ref)->left));
        preOrder(&((*root_ref)->right));
    }
}

void order(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        order(&((*root_ref)->left));
        printf("%d %d %s %s\n",(*root_ref)->data.initialCEP, (*root_ref)->data.endCEP, (*root_ref)->data.city, (*root_ref)->data.state);
        order(&((*root_ref)->right));
    }
}

struct Node* searchByCEP(struct Node **root_ref, int key){
    if(root_ref == NULL) return NULL;

    struct Node* currentNode = *root_ref;

    while(currentNode != NULL){
        if((key >= currentNode->data.initialCEP) && (key <= currentNode->data.endCEP)){
            return currentNode;
        }

        if(key > currentNode->data.initialCEP){
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }
    
    return NULL;
}

void rotationLL(struct Node **A){
    struct Node *B;

    B = (*A)->left;
    (*A)->left = B->right;
    B->right = *A;

    (*A)->height = bigger(heightNode((*A)->left), heightNode((*A)->right)) + 1;
    B->height = bigger(heightNode(B->left),(*A)->height) + 1;

    *A = B;
}

void rotationRR(struct Node **A){
    struct Node *B;
    B = (*A)->right;
    (*A)->right = B->left;
    B->left = (*A);
    (*A)->height = bigger(heightNode((*A)->left),heightNode((*A)->right)) + 1;
    B->height = bigger(heightNode(B->right),(*A)->height) + 1;
    (*A) = B;
}

void rotationLR(struct Node **A){
    rotationRR(&(*A)->left);
    rotationLL(A);
}

void rotationRL(struct Node **A){
    rotationLL(&(*A)->right);
    rotationRR(A);
}

int insert(struct Node **root_ref, struct Data newData){
    int res;
    if(*root_ref == NULL){
        struct Node *newNode;

        newNode = malloc(sizeof(struct Node));
        if(newNode == NULL) return 0;

        newNode->data = newData;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;

        *root_ref = newNode;
        return 1;
    }

    struct Node *currentNode = *root_ref;
    if(newData.initialCEP < currentNode->data.initialCEP){
        if((res = insert(&(currentNode->left), newData)) == 1){
            if(balancingTree(currentNode) >= 2){
                if(newData.initialCEP < (*root_ref)->left->data.initialCEP){
                    rotationLL(root_ref);
                } else{
                    rotationLR(root_ref);
                }
            }
        }
    }else{
        if(newData.initialCEP > currentNode->data.initialCEP){
            if((res = insert(&(currentNode->right), newData)) == 1){
                if(balancingTree(currentNode) >= 2){
                    if((*root_ref)->right->data.initialCEP < newData.initialCEP){
                        rotationRR(root_ref);
                    }else{
                        rotationRL(root_ref);
                    }
                }
            }
        } else {
            printf("ERROR\n");
            return 0;
        }
    }

    currentNode->height = bigger(heightNode(currentNode->left),heightNode(currentNode->right)) + 1;

    return res;
}
