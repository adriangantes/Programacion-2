/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 16 / 03 / 23
 */

#include "static_list.h"
void createEmptyList(tList* L){
    L->lastPos=LNULL; //lista vacia poniendo la ultima pos a nulo
}

bool isEmptyList(tList L){
    return L.lastPos==LNULL; //si es true la lista es vacia
}

tPosL first(tList L){
    return 0; //0 como primera posicion
}

tPosL last (tList L){
    return L.lastPos; //lastPos como ultima posicion
}

tPosL previous(tPosL p ,tList L){
    if(p==0)
        return LNULL; //si p es la primera posicion no hay posicion previa
    else
        return --p; //sino devuelve la posicion previa
}

tPosL next(tPosL p ,tList L){
    if(p==L.lastPos)
        return LNULL; // si p es la ultima posicion no hay posicion siguiente
    else
        return ++p; // sino devuelve la posicion siguiente
}

bool insertItem(tItemL d ,tPosL p ,tList* L){
    tPosL q;
    if(L->lastPos==max-1){
        return false; // si la lista esta llena no se puede insertar nada
    }else{
        L->lastPos++; //ultima posicion aumenta para añadir un item
        if(p==LNULL){ // si la posicion es nula
            L->member[L->lastPos]=d; //se añade al final de la lista

        }else{
            for(q=L->lastPos;q>p;q--){ //recorre la lista hasta la posicion y modifica las posiciones de los posteriores
                L->member[q]=L->member[q-1];
            }
            L->member[p]=d;
        }
        return true;
    }
}

void deleteAtPosition(tPosL p ,tList* L){
    tPosL q;
    for(q=p;q<L->lastPos;q++) //recorre la lista y modifica las posiciones posteriores al eliminado
        L->member[q]=L->member[q+1];
    L->lastPos--; //la lista pierde un elemento por lo que es mas pequeña
}

tItemL getItem(tPosL p ,tList L){
    return L.member[p]; //devuelve el item
}

void updateItem(tItemL d ,tPosL p ,tList* L){
    L->member[p]=d; //actualiza el item de esa posicion
}

tPosL findItem(tParticipantName d ,tList L){
    tPosL p;
    if(L.lastPos==LNULL) // si la lista esta vacia no hay items que encontrar
        return LNULL;
    else{
        for(p=0;(p<L.lastPos)&& (strcmp(d,L.member[p].participantName)!=0);p++); //recorre la lista hasta la ultima posicion o si encuentra al participante
        if(strcmp(d,L.member[p].participantName)==0){
            return p;//si lo encuentra devuelve su posicion
        }else{
            return LNULL; // sino devuelve nulo
        }
    }
}
