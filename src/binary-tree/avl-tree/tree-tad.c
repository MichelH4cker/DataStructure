#include <stdio.h>
#include <stdlib.h>
#include "tree-tad.h" //inclui os Prot�tipos

struct Node *createNewNode(){
    struct Node *newNode = malloc(sizeof(struct Node *));
    if(newNode != NULL)
        newNode = NULL;
    return newNode;
}

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

int fatorBalanceamento_Node(struct Node* Node){
    return labs(heightNode(Node->left) - heightNode(Node->right));
}

int bigger(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int emptyTree(struct Node **root_ref){
    if(root_ref == NULL)
        return 1;
    if(*root_ref == NULL)
        return 1;
    return 0;
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
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        //printf("%d\n",(*root_ref)->intData);
        //printf("Node %d: %d\n",(*root_ref)->intData,fatorBalanceamento_Node(*root_ref));
        printf("Node %d: %d\n",(*root_ref)->intData,heightNode(*root_ref));
        preOrder(&((*root_ref)->left));
        preOrder(&((*root_ref)->right));
    }
}

void order(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        order(&((*root_ref)->left));
        //printf("%d\n",(*root_ref)->intData);
        printf("Node %d: H(%d) fb(%d)\n",(*root_ref)->intData,heightNode(*root_ref),fatorBalanceamento_Node(*root_ref));
        order(&((*root_ref)->right));
    }
}

void postOrder(struct Node **root_ref){
    if(root_ref == NULL)
        return;
    if(*root_ref != NULL){
        postOrder(&((*root_ref)->left));
        postOrder(&((*root_ref)->right));
        printf("%d\n",(*root_ref)->intData);
    }
}

int searchByInt(struct Node **root_ref, int key){
    if(root_ref == NULL)
        return 0;
    struct Node* currentNode = *root_ref;
    while(currentNode != NULL){
        if(key == currentNode->intData){
            return 1;
        }
        if(key > currentNode->intData)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;
    }
    return 0;
}

//=================================
void rotationLL(struct Node **A){//LL
    printf("rotationLL\n");
    struct Node *B;
    B = (*A)->left;
    (*A)->left = B->right;
    B->right = *A;
    (*A)->height = bigger(heightNode((*A)->left),heightNode((*A)->right)) + 1;
    B->height = bigger(heightNode(B->left),(*A)->height) + 1;
    *A = B;
}

void rotationRR(struct Node **A){//RR
    printf("rotationRR\n");
    struct Node *B;
    B = (*A)->right;
    (*A)->right = B->left;
    B->left = (*A);
    (*A)->height = bigger(heightNode((*A)->left),heightNode((*A)->right)) + 1;
    B->height = bigger(heightNode(B->right),(*A)->height) + 1;
    (*A) = B;
}

void rotationLR(struct Node **A){//LR
    rotationRR(&(*A)->left);
    rotationLL(A);
}

void rotationRL(struct Node **A){//RL
    rotationLL(&(*A)->right);
    rotationRR(A);
}

int insert(struct Node **root_ref, int key){
    int res;
    if(*root_ref == NULL){//�rvore vazia ou n� folha
        struct Node *newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL)
            return 0;

        newNode->intData = key;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        *root_ref = newNode;
        return 1;
    }

    struct Node *currentNode = *root_ref;
    if(key < currentNode->intData){
        if((res = insert(&(currentNode->left), key)) == 1){
            if(fatorBalanceamento_Node(currentNode) >= 2){
                if(key < (*root_ref)->left->intData ){
                    rotationLL(root_ref);
                }else{
                    rotationLR(root_ref);
                }
            }
        }
    }else{
        if(key > currentNode->intData){
            if((res = insert(&(currentNode->right), key)) == 1){
                if(fatorBalanceamento_Node(currentNode) >= 2){
                    if((*root_ref)->right->intData < key){
                        rotationRR(root_ref);
                    }else{
                        rotationRL(root_ref);
                    }
                }
            }
        }else{
            printf("key duplicado!!\n");
            return 0;
        }
    }

    currentNode->height = bigger(heightNode(currentNode->left),heightNode(currentNode->right)) + 1;

    return res;
}

struct Node* searchSmallestNode(struct Node* currentNode){
    struct Node *node1 = currentNode;
    struct Node *node2 = currentNode->left;
    while(node2 != NULL){
        node1 = node2;
        node2 = node2->left;
    }
    return node1;
}

int removeNode(struct Node **root_ref, int key){
	if(*root_ref == NULL){// key n�o existe
	    printf("key n�o existe!!\n");
	    return 0;
	}

    int res;
	if(key < (*root_ref)->intData){
	    if((res = removeNode(&(*root_ref)->left,key)) == 1){
            if(fatorBalanceamento_Node(*root_ref) >= 2){
                if(heightNode((*root_ref)->right->left) <= heightNode((*root_ref)->right->right))
                    rotationRR(root_ref);
                else
                    rotationRL(root_ref);
            }
	    }
	}

	if((*root_ref)->intData < key){
	    if((res = removeNode(&(*root_ref)->right, key)) == 1){
            if(fatorBalanceamento_Node(*root_ref) >= 2){
                if(heightNode((*root_ref)->left->right) <= heightNode((*root_ref)->left->left) )
                    rotationLL(root_ref);
                else
                    rotationLR(root_ref);
            }
	    }
	}

	if((*root_ref)->intData == key){
	    if(((*root_ref)->left == NULL || (*root_ref)->right == NULL)){// n� tem 1 filho ou nenhum
			struct Node *oldNodede = (*root_ref);
			if((*root_ref)->left != NULL)
                *root_ref = (*root_ref)->left;
            else
                *root_ref = (*root_ref)->right;
			free(oldNodede);
		}else { // n� tem 2 filhos
			struct Node* temp = searchSmallestNode((*root_ref)->right);
			(*root_ref)->intData = temp->intData;
			removeNode(&(*root_ref)->right, (*root_ref)->intData);
            if(fatorBalanceamento_Node(*root_ref) >= 2){
				if(heightNode((*root_ref)->left->right) <= heightNode((*root_ref)->left->left))
					rotationLL(root_ref);
				else
					rotationLR(root_ref);
			}
		}
		if (*root_ref != NULL)
            (*root_ref)->height = bigger(heightNode((*root_ref)->left),heightNode((*root_ref)->right)) + 1;
		return 1;
	}

	(*root_ref)->height = bigger(heightNode((*root_ref)->left),heightNode((*root_ref)->right)) + 1;

	return res;
}
