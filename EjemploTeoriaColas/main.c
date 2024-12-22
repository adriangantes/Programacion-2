#include <stdio.h>

float power(float r, int n){
    if (n>0){
        return r*power (r,--n);
    }else{
        return 1;
    }
}

void print_list(tList L, tPosL p){

    if (!isEmptyList(L)){
        if (p != LNULL){
            printf("%d ",getItem(p,L));
            print_list (L, next(p,L));
        }
    }
}

int main() {
    float r=2.5;
    int n=5;
    printf("%f", power (r,n));

    return 0;
}
