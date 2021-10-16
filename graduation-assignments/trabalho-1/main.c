// NOME: MICHEL HECKER FARIA
// NUSP: 12609690

#include "main.h"

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
    int   inputInt;
    for (int data = 0; ; data++){   // insert all values
        scanf("%f", &inputFloat);
        inputInt = inputFloat;
        if (inputFloat == 0){       // end input
            break;
        } else {
            if (typeInsertion == 3){
                descendingInsert(head, inputFloat);
            }
            else{ 
                crescentInsert(head, inputFloat);
            }
        }
    
    }
}

int main (void){
    int type;
    scanf("%d", &type);

    int totalInputs;
    scanf("%d", &totalInputs);
        
    struct Node *head = NULL;
    for (int i = 0; i < totalInputs; i++){
        receiveInputs(&head, type);
    }

    int isFloat = itsFloat(head);

    showAllNodes(head, isFloat);
    destroyList(&head);
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