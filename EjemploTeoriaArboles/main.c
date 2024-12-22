#include <stdio.h>
#include "arboles_punteros.h"

tBinTree findItem (tItemT d, tBinTree Tree){
    if (isEmptyTree(Tree)){
        return TNULL;
    }else if (d == root(Tree)){
        return (Tree);
    }else{
        tBinTree found= findItem(d, leftChild(Tree));
        if (found==TNULL){
            found = findItem(d, rightChild(Tree));
        }
        return found;
    }
}

bool existsItem (tItemT d, tBinTree Tree){
    if (isEmptyTree(Tree)){
        return false;
    }else if (d == root(Tree)){
        return true;
    }else{
        return (existsItem(d, leftChild(Tree)) || existsItem(d, rightChild(Tree)));
    }
}

bool mayoresQue (tItemT d, tBinTree Tree){
    if (isEmptyTree(Tree)){
        return true;
    }else if (d >= root(Tree)){
        return false;
    }else{
        return (mayoresQue(d, leftChild(Tree)) && mayoresQue(d, rightChild(Tree)));
    }
}


int main() {
    return 0;
}
