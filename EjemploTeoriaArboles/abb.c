#include "abb.h"

void createEmptyTree(tBST* tree){
    *tree = BSTNULL;
}

bool createBSTNode (tBSTPos* p, tKey key){
    *p = malloc(sizeof(struct tBSTNode));
    if (*p != BSTNULL){
        (*p) -> key = key;
        (*p) -> left = BSTNULL;
        (*p) -> right = BSTNULL;
    }
    return *p != BSTNULL;
}

bool insertKey (tBST* tree, tKey key){
    if (isEmptyTree(tree)){
        return createBSTNode (tree, key);
    }else if(key == (*tree) -> key){
        return true;
    }else if (key < (*tree) -> key){
        return insertKey (&(*tree) -> left, key);
    }else{
        return insertKey (&(*tree) -> right, key);
    }
}

tBST leftChild (tBST tree){
    return (tree -> left);
}

tBST rightChild (tBST tree){
    return (tree -> right);
}

tKey root (tBST tree){
    return (tree -> key);
}

bool isEmptyTree (tBST tree){
    return (tree == BSTNULL);
}

tBST findKey (tBST tree, tKey key){
    if (isEmptyTree(tree)){
        return BSTNULL;
    }else if(key == tree->key){
        return tree;
    }else if (key < tree ->key){
        return findKey (tree-> left, key);
    }else{
        return findKey (tree-> right, key);
    }
}

void replace (tBST* subTree, tBST *auxTree){
    if (!isEmptyTree((*subTree)->right)){
        replace (&(*subTree)->right, auxTree);
    }else{
        (*auxTree)->key = (*subTree)->key;
        *auxTree = *subTree;
        (*subTree) = (*subTree) ->left;
    }
}

void removeKey (tBST* tree, tKey key){
    tBST aux;
    if (key < (*tree) ->key){
        removeKey (&(*tree) -> left, key);
    }else if (key > (*tree) ->key){
        removeKey (&(*tree) -> right, key);
    }else{
        aux = *tree;
        if (isEmptyTree((*tree)->right)){
            *tree = (*tree) -> left;
        }else if (isEmptyTree((*tree)->left)){
            *tree = (*tree) -> right;
        }else{
            replace (&(*tree)->left, &aux);
        }
        free(aux);
    }
}
