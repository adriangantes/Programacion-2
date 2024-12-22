#include "listas_punteros.h"

void createEmptyList (tList* L){
    *L=LNULL;
}

bool createNode(tPosL *p){
    *p=malloc(sizeof (struct tNode));
    return *p !=LNULL;
}

bool insertItem(tItemL d,tPosL p,tList* L){
    tPosL q,r;

    if(!createNode(&q))
        return false;
    else{
        q->data=d;
        q->next=LNULL;
        if(*L==LNULL){
            *L =q;
        }else if(p== LNULL){
            for(r=*L;r->next!=LNULL;r=r->next);
            r->next=q;
        }else if(p== *L){
            q->next=*L;
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

bool copyList(tList L,tList* M){
    tPosL p;
    bool result;

    createEmptyList(M);
    if(isEmptyList(L)){
        result=true;
    }else{
        for(p=L;(p!=LNULL)&& insertItem(getItem(p,L),LNULL,M);p=p->next);
        if(p==LNULL){
            result=true;
        }else{
            result=false;
            deleteList(M);
        }
    }
    return result;
}

void updateItem(tItemL d,tPosL p,tList* L){
    p->data=d;
}

tPosL findItem(tItemL d,tList L){
    tPosL p;
    for(p=L;(p!=LNULL) && (p->data!=d);p=p->next);
    return p;
}

tPosL first(tList L){
    return L;
}
tPosL last (tList L){
    tPosL p;
    for(p=L;p->next !=LNULL;p=p->next);
    return p;
}
tPosL previous(tPosL p,tList L){
    tPosL q;
    if (p==L){
        return LNULL;
    }else{
        for(q=L;q->next!=p;q=q->next);
        return q;
    }
}
tPosL next(tPosL p,tList L){
    return p->next;
}

bool isEmptyList(tList L){
    return L==LNULL;
}

tItemL getItem(tPosL p,tList L){
    return p->data;
}

void deleteList(tList* L){
    tPosL p;

    while (*L !=LNULL){
        p=*L;
        *L =(*L)->next;
        free(p);
    }
}

void deleteAtPosition(tPosL p,tList* L){
    tPosL q;
    if (p== *L){
        *L= (*L)->next;
    }else if(p->next ==LNULL){
        for(q=*L;q->next!=p;q=q->next);
        q->next=LNULL;
    }else{
        q=p->next;
        p->data=q->data;
        p->next=q->next;
        p=q;
    }
    free(p);
    p=LNULL;
}

