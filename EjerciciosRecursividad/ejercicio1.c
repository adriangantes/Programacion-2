#include <stdio.h>
#include <stdbool.h>

void noSupera(int cont){
    if (cont==2){
        printf ("\n2 muestras consecutivas superan 0.7");
    }else{
        printf ("\n4 muestras consecutivas superan 0.6");
    }
}

void supera (int tiempo_total, int muestras_totales, float media_muestra, int incrementos){
    printf ("\n\nNumero de preparados: %d", muestras_totales);
    printf ("\nTiempo empleado: %d", tiempo_total);
    printf ("\nLecturas que han incrementado la media: %d", incrementos);
    printf ("\nPreparados por minuto: %f", ((float)muestras_totales/(float)tiempo_total)*60);
    printf ("\nMedia de indice de acidez: %f", media_muestra);
}

int main() {
    int tiempo=0, tiempo_total=0, muestras_totales=0, cont7=0, cont6=0, incrementos=0;
    float muestra, media_muestra=0, media_temporal, total_muestras=0;
    bool fallo7=false, fallo6=false;

    while (tiempo!=-1){
        printf ("\nIntroduce tiempo: ");
        scanf ("%d", &tiempo);
        if (tiempo == -1){
            break;
        }
        printf ("Introduce indice de acidez: ");
        scanf ("%f", &muestra);

        total_muestras+=muestra;
        tiempo_total+=tiempo;
        muestras_totales++;
        media_temporal=media_muestra;
        if (muestras_totales==1){
            media_muestra=muestra;
        }else{
            media_muestra=(media_muestra+muestra)/2;
            if (media_temporal < media_muestra){
                incrementos++;
            }
        }

        if (muestra > 0.7 && cont7==0){
            cont7++;
        }else if (muestra > 0.7 && cont7==1){
            cont7++;
            fallo7=true;
        }else{
            cont7=0;
        }

        if (muestra >= 0.6 && cont6<3){
            cont6++;
        }else if (muestra >= 0.6 && cont6==3){
            cont6++;
            fallo6=true;
        }else{
            cont6=0;
        }
    }

    if (fallo7 || fallo6){
        printf ("\nNo se supera el control por:\n");
        if (fallo7){
            noSupera(2);
        }
        if (fallo6){
            noSupera(4);
        }
    }else{
        media_muestra = total_muestras/(float)muestras_totales;
        supera(tiempo_total, muestras_totales, media_muestra, incrementos);
    }

    printf("\n");
    return 0;
}
