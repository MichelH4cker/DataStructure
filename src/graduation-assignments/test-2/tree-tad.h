#ifndef __TREETAD_H__
#define __TREETAD_H__

#include "main.h"

struct Node;
struct Data;

/**
 * @brief 
 * 
 * @param root_ref 
 */
void freeTree(struct Node *root_ref);

/**
 * @brief 
 * 
 * @param root_ref 
 * @param newData 
 * @return int 
 */
int insert(struct Node **root_ref, struct Data newData);

/**
 * @brief 
 * 
 * @param root_ref 
 * @return int 
 */
int heightTree(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param root_ref 
 * @return int 
 */
int totalNodes(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param root_ref 
 * @param key 
 * @return int 
 */
struct Node* searchByCEP(struct Node **root_ref, int key);

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

#endif