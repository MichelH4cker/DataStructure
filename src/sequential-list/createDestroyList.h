#ifndef __CREATELIST_H__
#define __CREATELIST_H__

#include <stdio.h>
#include <stdlib.h>

#include "createDestroyList.h"
#include "main.h"

List* createList();

void freeList(List *list);

#endif