#ifndef __INSERTION_H__
#define __INSERTION_H__

#include "main.h"

struct Data;
struct Node;


/**
 * @brief Create a New Node struct
 * 
 * @param newData Struct Data to insert on node 
 * @return struct Node* 
 */
struct Node* createNewNode(struct Data newData);

struct Node* insert(struct Node *node, struct Data newData);

#endif