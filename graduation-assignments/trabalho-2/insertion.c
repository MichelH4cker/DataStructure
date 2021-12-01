#include "insertion.h"

int switchAxis(int axis){
    if (axis == X){
        return Y;     
    } else if (axis == Y){
        return Z;
    } else {
        return X;
    }
    
}

void hierarchyOfAxis(struct Node **newNode_ref, struct Node **currentNode_ref, int axis){
    printf("chegou nó atual com eixo x %f \n", (*currentNode_ref)->data.coordinate[axis]);

    struct Node *currentNode = *currentNode_ref;
    struct Node *newNode = *newNode_ref;

    if (currentNode == NULL) return;
    // quando entrar nessa função, não sabemos se o nó atual é maior ou igual ao próximo nó, precisa verificar
    if (currentNode->data.coordinate[axis] == currentNode->next->data.coordinate[axis]){ //verifica se nó atual é igual ao próximo nó
        printf("entrou no primeiro if \n");
        printf("=================== \n");
        axis = switchAxis(axis);
        hierarchyOfAxis(&newNode, &currentNode, axis);
    } else if (currentNode->next->data.coordinate[axis] > currentNode->data.coordinate[axis]) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        printf("a coordenada atual é %f, enquanto que a próxima é %f \n", currentNode->data.coordinate[axis], currentNode->next->data.coordinate[axis]);
        printf("entrou no segundo if \n");
        printf("=================== \n");
    } else {
        newNode->next = currentNode->next;
        currentNode = newNode;
        
        printf("entrou no terceiro if \n");
        printf("=================== \n");
    }
}

void push(struct Node **head_ref, struct Data data){
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){ // não alocado  
        return;
    }

    newNode->data = data;                 

    newNode->next = (*head_ref);          
    newNode->previous = NULL;     

    if (*head_ref != NULL){
        (*head_ref)->previous = newNode;  
    }

    (*head_ref) = newNode;                
}

void append(struct Node **head_ref, struct Data data){
    struct Node *lastNode = *head_ref;
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return; // não alocado 

    newNode->data = data;       
    newNode->next = NULL;       

    if ((*head_ref) == NULL){   
        newNode->previous == NULL;
        (*head_ref) = newNode;
        return;
    }

    while (lastNode->next != NULL){
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->previous = lastNode;
}

void sortedInsert(struct Node **head_ref, struct Data data, int axis){
    struct Node *currentNode = *head_ref;
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->data = data;
    
    if ((*head_ref) == NULL){ //cabeça vazia
        *head_ref = newNode;
    } else if ((*head_ref)->data.coordinate[axis] >= newNode->data.coordinate[axis]) {  //cabeçalho já é o maior
        (*head_ref)->previous = newNode;
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        currentNode = *head_ref;

        while (currentNode->next != NULL && currentNode->next->data.coordinate[axis] < newNode->data.coordinate[axis]) {
            currentNode = currentNode->next;
        }
        // ao sair do nó o próximo nó é nulo
        // ao sair do while, sabemos que o próximo nó é maior OU igual ao ao nó atual
        printf("vai entrar nó com eixo igual a: %f \n", currentNode->data.coordinate[axis]);

        if (currentNode->next == NULL){
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        

        if (currentNode->data.coordinate[axis] == 10.0){
            struct Node *randomHead = *head_ref;
            printf("espere um momento, vamos printar a data para ver o que acontece: %f \n", data.coordinate[axis]);
            showAllNodes(&randomHead);
        }
        

        printf("o próximo nó a este acima é: %f \n", currentNode->next->data.coordinate[axis]);

        hierarchyOfAxis(&newNode, &currentNode, axis);
        /*
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        */
        
    }   
}


/*
| x | 1 | 2 | 2 | 4 | 5 | 6 |
| y | 8 | 2 | 5 | 1 | 3 | 6 |
| z | 9 | 8 | 5 | 3 | 0 | 1 |
*/