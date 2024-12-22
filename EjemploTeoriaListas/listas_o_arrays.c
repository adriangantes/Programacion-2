#include "listas_o_arrays.h"

void createEmptyList(tList* L){
    L -> lastPos =LNULL;
}

bool insertItem (tItemL d, tPosL p, tList* L){
    tPosL i;

    if(L->lastPos==MAX-1){
        return false;
    }else{
        if(isEmptyList(*L) || d > L->data[L->lastPos]){
            L->lastPos++;
            L->data[L->lastPos] = d;
        }else{
            L->lastPos++;
            for(i=L->lastPos;i>0 && d<L->data[i-1];i--){
                L->data[i] = L->data[i-1];
            }
            L->data[i] = d;
        }
    }
    return true;
}

void updateItem(tItemL d, tPosL p,tList* L){
    L->data[p]=d;
}

bool copyList(tList  L, tList* M){
    tPosL p;
    createEmptyList(M);
    if (!isEmptyList(L)){
        for(p=first(L);p<=L.lastPos;p++){
            insertItem(getItem(p,L),p,M );
            //M->data[p] = L.data[p];
        }
    }
    return true;
}

tPosL first (tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL previous(tPosL p, tList L){
    if(p==0){
        return LNULL;
    }else{
        return --p;
    }
}

tPosL next(tPosL p, tList L){
    if(p==L.lastPos){
        return LNULL;
    }else{
        return ++p;
    }
}

bool isEmptyList(tList L){
    return L.lastPos==LNULL;
}

tItemL getItem(tPosL p, tList L){
    return L.data[p];
}

tPosL findItem (tItemL d, tList L){
    tPosL p;
    if(L.lastPos==LNULL){
        return LNULL;
    }else if ((d < L.data[0]) || (d> L.data[L.lastPos])){
        return LNULL;
    }else{
        for(p=0;(p<L.lastPos) && (d>L.data[p]);p++);
        if (L.data[p] == d){
            return p;
        }else{
            return LNULL;
        }
    }
}

void deleteList(tList* L){
    /*while (isEmptyList(*L) != true){
        deleteAtPosition(first (*L), L);
    }*/
    L->lastPos =LNULL;
}

void deleteAtPosition (tPosL p, tList* L){
    tPosL q;
    for (q=p;q<L->lastPos;q++){
        L->data[q]=L->data[q+1];
    }
    L->lastPos--;
}
