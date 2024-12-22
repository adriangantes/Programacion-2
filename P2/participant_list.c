/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel Marcos Trillo LOGIN 1: miguel.mt
 * AUTHOR 2: Adrián Edreira Gantes LOGIN 2: adrian.gantes
 * GROUP: 1.4
 * DATE: 28 / 04 / 23
 */

#include "participant_list.h"

void createEmptyListP (tListP* P){
    *P=NULLP; //P apunta a nulo para crear lista vacia
}

bool createNode(tPosP *p){
    *p=malloc(sizeof (struct tNode));
    return *p !=NULLP;
}

tPosP findPosition (tListP P, tItemP d){
    tPosP p;
    //recorremos la lista mientras que no llegue al final y la posicion que buscamos sea mayor(por ser lista ordenada)
    for ( p = P ; (p->next != NULLP) && (strcmp(p->next->dataP.participantName, d.participantName)<0); p = p->next);
    return p;
}

bool insertItemP(tItemP d,tListP* P){
    tPosP q;
    tPosP p;
    if(!createNode(&q))
        return false;
    else{
        q->dataP=d; //insertamos el item como unico elemento de la lista
        q->next=NULLP;
        if(*P==NULLP){
            *P =q; //si no hay elementos que P apunte al item
        }else if(strcmp((*P)->dataP.participantName, d.participantName)>0 ){ //si hay mas elementos lo insertamos al principio
            q->next = *P;
            *P = q;
        }else{
            p = findPosition(*P, d);
            q->next=p->next;
            p->next=q;
        }
        return true;
    }
}

void updateItemP (tItemP d, tPosP p, tListP* P){
    p->dataP=d;  //hacemos que data apunte al nuevo item
}

tPosP findItemP (tParticipantName d,tListP P){
    tPosP p;

    for(p=P;(p!=NULLP) && (strcmp(p->dataP.participantName, d)<0);p=p->next);  //recorremos la lista
    if (p != NULLP  &&  (strcmp(p->dataP.participantName, d)==0)){  //si el participante es igual al participante de la lista devuelve la posicion
        return p;
    }else{
        return NULLP; //sino devuelve nulo
    }
}

tPosP firstP (tListP P){
    return P;  //devuelve P ,que es el primer elemento de la lista
}
tPosP lastP (tListP P){
    tPosP p;
    for(p=P;p->next !=NULLP;p=p->next);  //recorre la lista hasta llegar al ultimo elemento
    return p;
}
tPosP previousP (tPosP p,tListP P){
    tPosP q;
    if (p==P){ //si es el primer elemento devuelve nulo
        return NULLP;
    }else{
        for(q=P;q->next!=p;q=q->next);  //sino recorre la lista hasta llegar al elemento previo al que buscamos
        return q;
    }
}
tPosP nextP (tPosP p,tListP P){
    return p->next;  //devuelve la posicion siguiente
}

bool isEmptyListP (tListP P){
    return P==NULLP;  //si P es nulo devuelve true sino false
}

tItemP getItemP (tPosP p,tListP P){
    return p->dataP;  //devuelve el item
}

void deleteAtPositionP (tPosP p,tListP* P){
    tPosP q;
    if (p== *P){
        *P= (*P)->next;  //si es el primer elemento, P apuntara a nulo
    }else if(p->next ==NULLP){
        for(q=*P;q->next!=p;q=q->next);  //si es el ultimo elemento lo elimina
        q->next=NULLP;
    }else{
        q=p->next;
        p->dataP=q->dataP;
        p->next=q->next;
        p=q;
    }
    free(p);  //elimina la posicion indicada
    p=NULLP;
}