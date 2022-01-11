#include "tree.h" 

void freeLGRoot(struct Node *node){
    if(node == NULL) return;

    freeLGRoot(&(*node->left));
    freeLGRoot(&(*node->right));    
    free(node);

    node = NULL;
}

int identifiesNodeType(char *uniqueIdentifier){
    char type[4];
    for (int i = 0; i < 3; i++){
        type[i] = uniqueIdentifier[i];
    }
    type[3] = '\0';
    
    char *dictionary[6] = {"OUT\0", "INP\0", "AND\0", "OR-\0", "XOR\0", "NOT\0"};
    
    for (int idType = 0; idType < 6; idType++){
        if (strcmp(type, dictionary[idType]) == 0){
            return idType;            
        }
    }
    
}

int totalLeafNodes(struct Node *root_ref){
    if (root_ref == NULL) return 0;

    if (root_ref->left == NULL && root_ref->right == NULL){
        return 1;
    }

    return (totalLeafNodes(root_ref->left) + totalLeafNodes(root_ref->right));
}

void searchAndInsertInput(struct Node *root_ref, char *charInput, int intInput){
    if (root_ref == NULL) return;

    if (strcmp(root_ref->data.uniqueIdentifier, charInput) == 0){
        root_ref->data.inputValue = intInput;
    }
    
    searchAndInsertInput(&(*root_ref->left), charInput, intInput);
    searchAndInsertInput(&(*root_ref->right), charInput, intInput);
    
}

void receiveInputLeafNodes(struct Node *root_ref, int amountOfLeafNodes){
    int i = 0;
    int intInput;
    char charInput[6];
    
    while (i < amountOfLeafNodes){
        scanf("%s %d\n", charInput, &intInput);
        searchAndInsertInput(&(*root_ref), charInput, intInput);
        i++;
    }
}

void checkForLeafNodes(struct Node *currentNode){
    if (currentNode == NULL) return;

    if (currentNode->left == NULL && currentNode->right == NULL){
        if (currentNode->data.typeOfNode != 1){
            printf("CIRCUIT ERROR\n");
            exit(-1);
        }
        
    }

    checkForLeafNodes(currentNode->left);
    checkForLeafNodes(currentNode->right);
}

void insertOperation (struct Node *currentNode_ref, struct Node *newNode_ref, struct Data newData, char direction, char fatherReference[6], int *inserted){
    if (*inserted) return;
    
    if (currentNode_ref == NULL) return;    
    

    if (strcmp(fatherReference, currentNode_ref->data.uniqueIdentifier) == 0){ // vai inserir
        if (direction == 'U' || direction == 'L'){ // esquerda ou único
            if (currentNode_ref->left != NULL) printf("CIRCUIT ERROR\n");
                
            currentNode_ref->left = newNode_ref;
            *inserted = 1;
        } else { // direita
            if (currentNode_ref->right != NULL) printf("CIRCUIT ERROR\n");
            currentNode_ref->right = newNode_ref;
            *inserted = 1;
        }
    } else { //não vai inserir
        insertOperation(currentNode_ref->left, &(*newNode_ref), newData, direction, fatherReference, &(*inserted));
        insertOperation(currentNode_ref->right, &(*newNode_ref), newData, direction, fatherReference, &(*inserted));
    }
}

void insert (struct Node** root_ref, struct Data newData, char direction, char fatherReference[6]){
    int inserted = 0;

    if(root_ref == NULL) return;
    
    struct Node *currentNode = *root_ref;
    struct Node *newNode = NULL;

    newNode = malloc(sizeof(struct Node));
    if(newNode == NULL) return;
    
    newNode->data  = newData;
    newNode->left  = NULL;
    newNode->right = NULL;

    if(*root_ref == NULL){ 
        *root_ref = newNode;
        return;
    }

    insertOperation(currentNode, newNode, newData, direction, fatherReference, &inserted);
    
    if (!inserted) {
        printf("CIRCUIT ERROR\n");
        exit(-1);
    }
}

int LGRootSolvesCircuit(struct Node *root_ref){
    if (root_ref == NULL) return 0;
    
    int leftValue = LGRootSolvesCircuit(&(*root_ref->left));
    int rightValue = LGRootSolvesCircuit(&(*root_ref->right));

    if (root_ref->data.typeOfNode == 0){  //OUTPUT
        root_ref->data.inputValue = leftValue;
        return leftValue;
    } else if (root_ref->data.typeOfNode == 1){  //INP (LEAF)
        // NOTHING TO DO, just return
        return root_ref->data.inputValue;
    } else if (root_ref->data.typeOfNode == 2){  //AND
        root_ref->data.inputValue = (leftValue && rightValue);
        return root_ref->data.inputValue;
    } else if (root_ref->data.typeOfNode == 3){  //OR
        root_ref->data.inputValue = (leftValue || rightValue);
        return root_ref->data.inputValue;
    } else if (root_ref->data.typeOfNode == 4){  //XOR
        root_ref->data.inputValue = !(leftValue || rightValue);
        return root_ref->data.inputValue;
    } else {  //NOT
        root_ref->data.inputValue = !(leftValue);
        return root_ref->data.inputValue;
    }    
}