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
 * @param root_ref 
 * @param intData 
 * @param flag 
 * @return int 
 */
int searchIntData(struct Node **root_ref, int intData, int flag);

/**
 * @brief 
 * 
 * @param root 
 * @return int 
 */
int treeMinimum(struct Node **root, int flag);

/**
 * @brief 
 * 
 * @param root 
 * @return int 
 */
int treeMaximum(struct Node **root, int flag);

/**
 * @brief 
 * 
 * @param root_ref 
 * @return int 
 */
int treeHeight(struct Node **root_ref);

/**
 * @brief 
 * 
 * @param node 
 * @return int 
 */
int totalNodes(struct Node **root_ref);

#endif