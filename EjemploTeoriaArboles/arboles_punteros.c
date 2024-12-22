#include "arboles_punteros.h"

void createEmptyTree(tBinTree *T){
    *T = TNULL;
}

bool createNode (tPosT *p){
    *p = malloc (sizeof(struct tNodeT));
    return *p != TNULL;
}

bool buildTree (tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T){
    if (createNode(T)){
        (*T)-> data = d;
        (*T)-> left = LTree;
        (*T)-> right = RTree;
        return true;
    }
    return false;
}

tBinTree leftChild (tBinTree T){
    return (T -> left);
}

tBinTree rightChild (tBinTree T){
    return (T -> right);
}

tItemT root (tBinTree T){
    return (T -> data);
}

bool isEmptyTree (tBinTree T){
    return (T == TNULL);
}

bool insertKey (tBST tree, tKey key){
    if (isEmptyTree(*tree)){
        return createBSTNode (tree, key);
    }else if ()
}