// NOME: MICHEL HECKER FARIA
// NUSP: 12609690

#include "main.h"

int len(struct Node *head){
    int len = 0;
    struct Node *node = head;
    
    while (node != NULL){
        node = node->next;
        len++;
    }
    
    return len;
}

int itsFloat(struct Node *head_ref){
    struct Node *currentNode = head_ref;

    float dataFloat;
    int dataInt;

    while (currentNode != NULL){
        dataFloat = currentNode->data;
        dataInt = dataFloat;
        if (dataFloat - dataInt > 0){
            return 1; // is float
        }

        currentNode = currentNode->next;
        
    }

    return 0; //isn't float

}

void showAllNodes(struct Node *head_ref, int isFloat){
    struct Node *node = head_ref;    

    while (node != NULL){
        if (node->data == 0){
            break;
        }
        
        if (isFloat){
            printf("%0.1f ", node->data);

        } else{
            printf("%0.0f ", node->data);
        }
        
        node = node->next;
    }
    
}
    
void receiveInputs(struct Node **head, int typeInsertion){
    float inputFloat;
    while (1) {
        scanf("%f", &inputFloat);   
        if (inputFloat == 0){
            break;
        }
        if (typeInsertion == 1){
            append(head, inputFloat);
        }
        else{ 
            crescentInsert(head, inputFloat);
        } 
    }
    append(head, 0);
}

int main (void){
    int type;
    scanf("%d", &type);

    int totalInputs;
    scanf("%d", &totalInputs);
        
    struct Node *main = NULL;

    for (int i = 0; i < totalInputs; i++){
        struct Node *other = NULL;
        if (i == 0){
            receiveInputs(&main, type); 
            
        } else {
            receiveInputs(&other, type);
            merge(&main, &other);
        }        
    }
    
    int isFloat = itsFloat(main);
    struct Node *decrescent = NULL;

    if (type == 3){
        float input;
        while (1){
            if (main == NULL){
                break;
            }
            input = main->data;
            if (input == 0){
                main = main->next;    
                continue;
            }
            
            push(&decrescent, input);
            main = main->next;    

        } 

        showAllNodes(decrescent, isFloat);

    } else {
        showAllNodes(main, isFloat);
    }

    destroyList(&main);
    destroyList(&decrescent);

}

/*
####### TIPOS DE ENTRADA LISTA #######

1 - listas de dados que já estão ordenadas, sendo necessário 
apenas a unificação das duas listas (merge)

2 - contém listas de dados que não foram ordenadas

3 - listas não ordenadas, mas que devem ser exibidas 
na ordem inversa  (decrescente) 
no final do processo de ordenação e  unificação

*/