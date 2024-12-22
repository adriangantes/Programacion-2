#ifndef EJEMPLOTEORIAARBOLES_ARBOLES_PUNTEROS_H
#define EJEMPLOTEORIAARBOLES_ARBOLES_PUNTEROS_H

#include <stdbool.h>
#include <stdlib.h>
#include "arboles_punteros.h"

#define TNULL NULL

typedef int tItemT;
typedef struct tNodeT *tPosT;
struct tNodeT{
    tItemT data;
    tPosT right;
    tPosT left;
};
typedef tPosT tBinTree;

void createEmptyTree(tBinTree *T);
bool buildTree (tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T);
tBinTree leftChild (tBinTree T);
tBinTree rightChild (tBinTree T);
tItemT root (tBinTree T);
bool isEmptyTree (tBinTree T);

#endif //EJEMPLOTEORIAARBOLES_ARBOLES_PUNTEROS_H
