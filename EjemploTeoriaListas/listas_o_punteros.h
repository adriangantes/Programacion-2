#ifndef EJEMPLOTEORIA_LISTAS_O_PUNTEROS_H
#define EJEMPLOTEORIA_LISTAS_O_PUNTEROS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define LNULL NULL

typedef int tItemL;
typedef struct tNode* tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

/* Prototipos de funciones */

void createEmptyList(tList* L);
bool insertItem(tItemL d,tPosL p,tList* L);
void updateItem(tItemL d,tPosL p,tList* L);
bool copyList(tList L,tList* M);
tPosL first(tList L);
tPosL last (tList L);
tPosL previous(tPosL p,tList L);
tPosL next(tPosL p,tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p,tList L);
tPosL findItem(tItemL d,tList L);
void deleteList(tList* L);
void deleteAtPosition(tPosL p,tList* L);

#endif //EJEMPLOTEORIA_LISTAS_O_PUNTEROS_H
