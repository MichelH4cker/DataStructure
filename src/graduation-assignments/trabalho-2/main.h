#ifndef __MAIN_H__
#define __MAIN_H__

#define X 0
#define Y 1
#define Z 2
#define ACTIVATED 1
#define DISABLED 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertion.h"
#include "commands.h"
#include "file.h"

struct RGB {
    int red;
    int green;
    int blue;
};

struct Data {
    float coordinate[3];
    struct RGB rgb;
    int ID;
};

struct Node {
    int timesAccessed;
    struct Data data;
    struct Node *next;
    struct Node *previous;
};

#endif
