#ifndef __TREETAD_H__
#define __TREETAD_H__

#include "main.h"

struct Node;

struct Node* createNewNode();

void freeNode(struct Node* Node);

void freeTree(struct Node *root_ref);

int insert(struct Node **root_ref, int data);

int removeNode(struct Node **root_ref, int key);

int emptyTree(struct Node **root_ref);

int heightTree(struct Node **root_ref);

int totalNodes(struct Node **root_ref);

int searchByInt(struct Node **root_ref, int key);

void preOrder(struct Node **root_ref);

void order(struct Node **root_ref);

void postOrder(struct Node **root_ref);

#endif