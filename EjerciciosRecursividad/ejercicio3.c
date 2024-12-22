#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 24

typedef struct{
    char nif[8];
    bool este;
    int presupuesto;
    int num_socios;
    int telefono;
    char direccion[50];
    int poblacion;
    int importe;
    struct{
        int dia;
        int mes;
        int year;
    }fecha;
}tClub;

struct tLiga{
    tClub club[MAX];
}liga;

int pres_max (){
    int maximo=0, pos_maximo=0;
    for (int i=0 ; i < MAX ; i++){
        if (maximo < liga.club[i].presupuesto ){
            maximo=liga.club[i].presupuesto;
            pos_maximo=i;
        }
    }
    return pos_maximo;
}

int ratio (){
    float minimo=0;
    int pos_minimo=0;
    for (int i=0 ; i < MAX ; i++){
        if (minimo > (float)liga.club[i].importe/(float)liga.club[i].presupuesto){
            minimo = (float)liga.club[i].importe/(float)liga.club[i].presupuesto;
            pos_minimo=i;
        }
    }
    return pos_minimo;
}

int main() {
    scanf("%s",liga.club[0].nif);
    scanf("%s",liga.club[1].nif);
    liga.club[0].presupuesto =100;
    liga.club[1].presupuesto =101;
    liga.club[0].importe =30;
    liga.club[1].importe =36;

    printf("Club con el presupuesto maximo: %s\n", liga.club[pres_max()].nif);
    printf("Club con el mejor ratio: %s\n", liga.club[ratio()].nif);
    return 0;
}
