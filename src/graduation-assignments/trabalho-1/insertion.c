#include "insertion.h"

void merge(struct Node** headMain, struct Node** head) {
    struct Node* main = *headMain;
    struct Node* other = *head;
    struct Node* helperMain = *headMain;
    struct Node* helperOther = *head;
    int flag = 0;

    while (1) {
        if (other == NULL || other->data == 0) {
            break;
        }

        if (other->data < main->data && other->data != 0 && flag == 0) {
            *headMain = other;
            while (other->data < main->data && other->data != 0) {
                helperOther = other;
                other = other->next;
            }
            helperMain = helperOther;
            helperOther->next = main;
        }
        flag++;
        if (main->data <= other->data && main->data != 0) {
            helperMain = main;
            main = main->next;
        }
        else if (main->data != 0) {
            helperOther = other;
            other = other->next;
            helperOther->next = main;
            helperMain->next = helperOther;
            helperMain = helperOther;
        }
        else {
            helperMain->next = other;
            return;
        }
    }
}

void crescentInsert(struct Node** head_ref, float inputData) {
    struct Node* newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->data = inputData;

    struct Node* currentNode = *head_ref;

    if (*head_ref == NULL || (*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    else {
        currentNode = *head_ref;
        while (currentNode->next != NULL && currentNode->next->data < newNode->data) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }

}

void descendingInsert(struct Node** head_ref, float input) {
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = input;

    struct Node* currentNode = *head_ref;

    if (*head_ref == NULL || (*head_ref)->data <= newNode->data) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    else {
        currentNode = *head_ref;

        while (currentNode->next != NULL && currentNode->next->data > newNode->data) {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return;
    }

}

void append(struct Node** head, float inputData) {
    struct Node* node;
    node = malloc(sizeof(struct Node));
    if (node == NULL) {
    return;
    }
    node->data = inputData;
    node->next = NULL;

    struct Node* lastNode = *head;

    if ((*head) == NULL) { // lista vazia insere no início
        *head = node;
        return;
    }
    else {
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = node;
        return;
    }

}

void push(struct Node** head, float inputData) {
    struct Node* node;
    node = malloc(sizeof(struct Node));

    if (node == NULL || head == NULL) {
        return; //error 
    }
    else {
        node->data = inputData;     // novo nó recebe o dado de entrada
        node->next = (*head);       // próximo nó recebe o conteúdo antigo da head
        *head = node;               // conteúdo do ponteiro head recebe novo nó

        return;
    }

}