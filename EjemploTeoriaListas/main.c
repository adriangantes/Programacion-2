#include <stdio.h>
#include "listas_array.h"
//#include "listas_dobles.h"
//#include "listas_o_punteros.h"
//#include "listas_o_arrays.h"
//#include "listas_punteros.h"


int count_elements(tList L) {//devuelve un entero
    tPosL p;
    int cont=0;
    for(p=first(L); p!=LNULL; cont++, p=next(p,L));
    return cont;
}

bool exist_item(tList L, tItemL a){
    if ((findItem(a, L) != LNULL) && (getItem(findItem(a,L), L)==a)){
        return true;
    }
    return false;
}

bool equal_sets(tList L, tList M){
    tPosL p,q;
    tList X;
    int cont=0;

    if(isEmptyList(L) && isEmptyList(M)){
        return true;
    }else if (isEmptyList(L) || isEmptyList(M)){
        return false;
    }else{
        if (count_elements(L)!= count_elements(M)){
            return false;
        }else{
            copyList(M,&X);
            for(p=first(L); (p!=LNULL); p=next(p,L)){
                for(q=first(X);(q!=LNULL); q=next(q,X)){
                    if (getItem(p,L) == getItem(q,X)){
                        cont++;
                        deleteAtPosition(q,&X);
                        break;
                    }
                }
            }
            if(cont==count_elements(L)){
                return true;
            }else{
                return false;
            }
        }
    }
}

bool equal_lists (tList L, tList M){
    tPosL p,q;

    if(isEmptyList(L) && isEmptyList(M)){
        return true;
    }else if (isEmptyList(L) || isEmptyList(M)){
        return false;
    }else{
        for(p=first(L), q=first(M); (p!=LNULL) && (q!=LNULL) && (getItem(p,L)==getItem(q,M));p=next(p,L), q=next(q,M));
        return ((p==LNULL) && (q==LNULL));
    }
}

void print_list(tList L) {
    tPosL p;
    printf("( ");
    if (!isEmptyList(L)) {
        for (p = first(L); p != LNULL; p = next(p, L)) {
            printf("%d ", getItem(p, L));
        }
    }
    printf(")");
}

void showList (tPosL pos, tList L){
    if (pos != LNULL){
        printf ("  %d", getItem(pos, L));
        showList(next(pos,L), L);
    }
}

int main() {
    tList L,M;
    createEmptyList(&L);

    insertItem (1,LNULL,&L);
    insertItem (4,LNULL,&L);
    insertItem (2,next(first(L),L),&L);
    insertItem (3,last(L),&L);


    copyList(L, &M);
    //insertItem (5,previous(last(M),M),&M);

    /*createEmptyList(&M);
    insertItem (1,LNULL,&M);
    insertItem (4,LNULL,&M);
    insertItem (2,next(first(M),M),&M);
    insertItem (3,last(M),&M);*/

    printf("Lista L: ");
    print_list(L);

    printf("\nLista M: ");
    print_list(M);

    printf ("\n\nElementos de la lista L: %d",count_elements(L));
    printf ("\nElementos de la lista M: %d",count_elements(M));

    printf ("\n\nLas listas son iguales? %s", equal_lists(L,M) ? "Yes":"No");
    printf ("\nLas listas tienen los mismos valores? %s", equal_sets(L,M) ? "Yes":"No");

    printf ("\n\nEl valor 3 esta en la lista L? %s", exist_item(L,3) ? "Yes":"No");
    printf ("\nEl valor 5 esta en la lista M? %s", exist_item(M,5) ? "Yes":"No");

    /*deleteLast(&L);
    printf("\n\nLista L: ");
    print_list(L);

    backRotate(&M);
    printf("\n\nLista M: ");
    print_list(M);

    backRotate(&L);
    printf("\n\nLista L: ");
    print_list(L);*/

    printf("\n");
    return 0;
}
