//
// Created by alonso on 23/11/18.
//

#include <stdlib.h>
#include "avl.h"

bool createAVLNode(tAVLPos *p, tKey key) {
    *p = malloc(sizeof(struct tAVLNode));
    if (*p != NULLAVL) {
        (*p)->key = key;
        (*p)->bf = 0;
        (*p)->left = NULLAVL;
        (*p)->right = NULLAVL;
    }
    return *p != NULLAVL;
}

void createEmptyTree(tAVL *tree) {
    *tree = NULLAVL;
}

// Single rotations: LL and RR rotations

void ll_rotation(tAVL *tree, tAVL aux1) {
    (*tree)->left = aux1->right;
    aux1->right = *tree;

    if(aux1->bf == 0) { // this case mau occurs only in a removeKey operation
        (*tree)->bf = -1;
        aux1->bf = 1;
    }
    else { // actually: aux1->bf == -1
        (*tree)->bf = 0;
        aux1->bf = 0;
    }
    *tree = aux1;
}

void rr_rotation(tAVL *tree, tAVL aux1) {
    (*tree)->right= aux1->left;
    aux1->left= *tree;

    if (aux1->bf == 0) { // this case mau occurs only in a removeKey operation
        (*tree)->bf = 1;
        aux1->bf = -1;
    }
    else { // actually: aux1->bf == 1
        (*tree)->bf = 0;
        aux1->bf = 0;
    }
    *tree = aux1;
}

// Double rotations: RL and LR rotations

void lr_rotations(tAVL *tree, tAVL aux1) {
    tAVL aux2;

    aux2 = aux1->right;
    // move the children of aux2 to their final positions
    (*tree)->left = aux2->right;
    aux1->right = aux2->left;
    // set the new children of aux2
    aux2->right = (*tree);
    aux2->left = aux1;

    // set the new bf of aux1
    if (aux2->bf == 1)
        aux1->bf = -1;
    else
        aux1->bf = 0;

    // set the new bf of tree
    if (aux2->bf == -1)
        (*tree)->bf = 1;
    else
        (*tree)->bf = 0;

    // the root of the tree is now aux2
    aux2->bf = 0;
    (*tree) = aux2;
}

void rl_rotations(tAVL *tree, tAVL aux1) {
    tAVL aux2;

    aux2 = aux1->left;
    // move the children of aux2 to their final positions
    (*tree)->right = aux2->left;
    aux1->left = aux2->right;
    // set the new children of aux2
    aux2->left = (*tree);
    aux2->right = aux1;

    // set the new bf of tree
    if (aux2->bf == 1)
        (*tree)->bf = -1;
    else
        (*tree)->bf = 0;

    // set the new bf of aux1
    if (aux2->bf == -1)
        aux1->bf = 1;
    else
        aux1->bf = 0;

    // the root of the tree is now aux2
    aux2->bf = 0;
    (*tree) = aux2;
}




bool insertAVLKey(tAVL *tree, tKey key, bool *hh) {
    // hh==true means an incremenat in the height of A as a result of an insertion}

    tAVL auxTree;
    bool result;

    if (isEmptyTree(*tree)) {
        result = createAVLNode(tree, key);
        *hh = true;
    }
    else if (key == (*tree)->key) {
        *hh =false; // nothing happens when key is currently stored in the AVL
        result = true;
    }
    else if (key < (*tree)->key) {
        result = insertAVLKey(&(*tree)->left, key, hh);
        if (*hh && result) { // left branch has increased its height
            switch ((*tree)->bf) {
                case 1:
                    (*tree)->bf = 0;
                    *hh = false;
                    break;

                case 0:
                    (*tree)->bf = -1;
                    break;

                case -1:
                    auxTree = (*tree)->left;
                    if (auxTree->bf == -1)
                        ll_rotation(tree, auxTree);
                    else
                        lr_rotations(tree, auxTree);

                    *hh = false;
                    break;
            }
        }
    }
    else { // (key > (*tree)->key)
        result = insertAVLKey(&(*tree)->right, key, hh);
        if (*hh && result) { // right branch has increased its height
            switch ((*tree)->bf) {
                case -1:
                    (*tree)->bf = 0;
                    *hh = false;
                    break;

                case 0:
                    (*tree)->bf = 1;
                    break;

                case 1:
                    auxTree = (*tree)->right;
                    if (auxTree->bf == 1)
                        rr_rotation(tree, auxTree);
                    else
                        rl_rotations(tree, auxTree);

                    *hh = false;
                    break;
            }
        }
    }

    return result;
}

bool insertKey(tAVL *tree, tKey key) {
    bool hhFlag=false;

    return insertAVLKey(tree, key, &hhFlag);
}

tAVL leftChild(tAVL tree) {
    return tree->left;
}

tAVL rightChild(tAVL tree) {
    return tree->right;
}

tKey root(tAVL tree) {
    return tree->key;
}

bool isEmptyTree(tAVL tree) {
    return tree == NULLAVL;
}

tAVL findKey(tAVL tree, tKey key) {
    if (isEmptyTree(tree))
        return NULLAVL;
    else if (key == tree->key)
        return tree;
    else if (key < tree->key)
        return findKey(tree->left, key);
    else // (key > tree->key)
        return findKey(tree->right, key);
}


// recompute the balance factors of the LEFT child of subtree, where
// a node that has caused a decrease in the height of that child has been removed
void balance_left_branch(tAVL *subTree, bool *hh) {
    tAVL auxTree;

    switch ((*subTree)->bf) {
        case -1:
            (*subTree)->bf = 0;
            break;

        case 0:
            (*subTree)->bf = 1;
            *hh =  false;
            break;

        case 1:
            auxTree = (*subTree)->right;
            if (auxTree->bf >= 0) {
                if (auxTree->bf == 0)   // This is the special case where a
                    *hh = false;        // single rotation does not reduce height
                rr_rotation(subTree, auxTree);
            }
            else
                rl_rotations(subTree, auxTree);
    }
}


// recompute the balance factors of the RIGHT child of subtree, where
// a node that has caused a decrease in the height of that child has been removed
void balance_right_branch(tAVL *subTree, bool *hh) {
    tAVL auxTree;

    switch ((*subTree)->bf) {
        case 1:
            (*subTree)->bf = 0;
            break;

        case 0:
            (*subTree)->bf = -1;
            *hh =  false;
            break;

        case -1:
            auxTree = (*subTree)->left;
            if (auxTree->bf <= 0) {
                if (auxTree->bf == 0)   // This is the special case where a
                    *hh = false;        // single rotation does not reduce height
                ll_rotation(subTree, auxTree);
            }
            else
                lr_rotations(subTree, auxTree);
    }
}




// Auxiliary function for removeAVLKey
void replace(tAVL *subTree, tAVL *auxTree, bool *hh) { // Replace the content of a node by its predecessors’
    if (!isEmptyTree((*subTree)->right)) {
        replace(&((*subTree)->right), auxTree, hh); // Going down the right branch
        if (*hh)
            balance_right_branch(subTree, hh);
    }
    else {
        (*auxTree)->key = (*subTree)->key;  // We replace the data fields of the node
        *auxTree = *subTree;                // We mark the node on which we will call free()
        (*subTree) = (*subTree)->left;      // We re-link the tree structure by “skiping” the node to be deleted
        *hh =true;
    }
}

void removeAVLKey(tAVL *tree, tKey key, bool *hh) {
    tAVL aux;

    if (key < (*tree)->key) {                 // If the key is smaller, continue in the left subtree
        removeAVLKey(&(*tree)->left, key, hh);
        if (*hh)
            balance_left_branch(tree, hh);
    }
    else if (key > (*tree)->key) {           // If the key is larger, continue in the right subtree
        removeAVLKey(&(*tree)->right, key, hh);
        if (*hh)
            balance_right_branch(tree, hh);
    }
    else                                    // Key located, proceed to delete the node
    {
        aux = *tree;
        if (isEmptyTree((*tree)->right)) {   // If it has no right child, replace by the left one
            *tree = (*tree)->left;          // (this covers the no-children case, too)
            *hh = true;
        }
        else if (isEmptyTree((*tree)->left)) {// If it has no left child, replace by the right one
            *tree = (*tree)->right;
            *hh = true;
        }
        else {                               // If it has two children, we call replace() passing
            replace(&(*tree)->left, &aux, hh);  // its left subtree as first argument
            if (*hh)
                balance_left_branch(tree, hh);
        }
        free(aux);
    }
}


void removeKey(tAVL *tree, tKey key) {
    bool hhFlag=false;

    return removeAVLKey(tree, key, &hhFlag);
}


