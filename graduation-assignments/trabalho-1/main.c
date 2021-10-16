#include "main.h"

void showAllNodes(struct Node *array, int totalInputs){
    struct Node *currentNode;
    float ithInput;
    printf("entrou no showAllNodes \n");
    for (int positionOnArray = 0; positionOnArray < totalInputs; positionOnArray++){
        printf("entrou no primeiro for! \n");
        *currentNode = array[positionOnArray]; // receive head_ref
        for (int i = 0; ithInput != 0; i++){   // run all nodes
            printf("entrou no segundo for! \n");
            ithInput = (*currentNode).data;
            printf("Input: %f \n", ithInput);
            currentNode = (*currentNode).next;
        }
        
    }
    

}

int receiveInputs(struct Node *array, int totalInputs){
    float input;
    for (int positionOnArray = 0; positionOnArray < totalInputs; positionOnArray++){    // run all lists
        struct Node *head = NULL;
        for (int data = 0; ; data++){   // insert all values
            scanf("%f", &input);
            crescentInsert(&head, input);
            printf("o input inserido foi %f \n", input);
            if (input == 0){
                array[positionOnArray] = *head;
                break;
            }
            
        }
        
        
    }
}

int main (void){
    int type;
    scanf("%d", &type);

    int totalInputs;
    scanf("%d", &totalInputs);

    struct Node array[totalInputs];
    
    //receive inputs
    receiveInputs(array, totalInputs);
    printf("\n %f \n\n", array[0].next->data);
    showAllNodes(array, totalInputs);
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