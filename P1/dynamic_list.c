/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 16 / 03 / 23
 */

#include "dynamic_list.h"

void createEmptyList (tList* L){
    *L=LNULL;//crear lista vacia
}

bool createNode(tPosL *p){
    *p=malloc(sizeof (struct tNode));//crear nodo
    return *p !=LNULL;
}

bool insertItem(tItemL d,tPosL p,tList* L){
    tPosL q,r;

    if(!createNode(&q))
        return false;//si el nodo esta vacio devuelve false
    else{
        q->data=d;//añade el elemento a la lista
        q->next=LNULL;
        if(*L==LNULL){//si no hay elementos d sera el primer elemento de la lista
            *L =q;
        }else if(p== LNULL){//si no se inserta la posicion del elemento a añadir
            for(r=*L;r->next!=LNULL;r=r->next);//recorremos la lista
            r->next=q;//y q sera el ultimo elemento de la lista
        }else if(p== *L){//si la posicion apunta al primer elemento de la lista
            q->next=*L;//el elemento se inserta al principio
            *L =q;
        }else{
            q->data=p->data;
            p->data=d;
            q->next=p->next;
            p->next=q;
        }
        return true;
    }
}

void updateItem(tItemL d,tPosL p,tList* L){
    p->data=d;//inserta en la posicion el elemento asignado
}

tPosL findItem(tParticipantName d,tList L){
    tPosL p;
    for(p=L;(p!=LNULL) && (strcmp(p->data.participantName,d)!=0);p=p->next);//recorre la lista y busca si el nombre aparece en la lista
    return p;//devuelve la posicion donde esta el nombre o nulo si no esta en la lista
}

tPosL first(tList L){
    return L;//devuelve el primer elemento de la lista
}
tPosL last (tList L){
    tPosL p;
    for(p=L;p->next !=LNULL;p=p->next);//recorre la lista y devuelve el ultimo elemento
    return p;
}
tPosL previous(tPosL p,tList L){
    tPosL q;
    if (p==L){//si la posicion es la primera no hay elemento previo
        return LNULL;
    }else{
        for(q=L;q->next!=p;q=q->next);//sino recorre la lista hasta el anterior del elemento
        return q;
    }
}
tPosL next(tPosL p,tList L){
    return p->next;//devuelve el elemento siguiente
}

bool isEmptyList(tList L){
    return L==LNULL;//devuelve true si esta vacia sino false
}

tItemL getItem(tPosL p,tList L){
    return p->data;//devuelve el item de la posicion indicada
}

void deleteAtPosition(tPosL p,tList* L){
    tPosL q;
    if (p== *L){//si la posicion es la primera
        *L= (*L)->next;//apunta a la siguiente
    }else if(p->next ==LNULL){//si es la ultima posicion
        for(q=*L;q->next!=p;q=q->next);
        q->next=LNULL;//elimina el ultimo elemento de la lista
    }else{
        q=p->next;
        p->data=q->data;
        p->next=q->next;//elimina el elemento requerido
        p=q;
    }
    free(p);//vacia la memoria de p
    p=LNULL;
}