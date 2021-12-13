#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertion.h"
#include "information.h"
#include "file.h"

#define CPF  0
#define NREG 1

struct Data {
    int dataArray[2];
    // 0 -> CPF
    // 1 -> NReg
};

struct Node {
    struct Data data;
    struct Node *right;
    struct Node *left;
};

#endif