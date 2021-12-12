#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include "main.h"

struct Data;
struct Node;

/**
 * @brief 
 * 
 * @param root_ref 
 */
void preOrder(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param root_ref 
 */
void order(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param root_ref 
 */
void postOrder(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param node 
 * @return int 
 */
int totalNodes(struct Node *root_ref);

#endif