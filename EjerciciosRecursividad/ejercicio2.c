#include <stdio.h>
#define MAX 6

void media (float nota_media, float nota_presentada){
    if (nota_media<5){
        printf ("Nota media: SUSPENSO (%.1f)",nota_media);
    }else if (5<=nota_media && nota_media<=6.9){
        printf ("Nota media: APROBADO (%.1f)",nota_media);
    }else if (7<=nota_media && nota_media<=8.9){
        printf ("Nota media: NOTABLE (%.1f)",nota_media);
    }else if (nota_media>=9){
        printf ("Nota media: SOBRESALIENTE (%.1f)",nota_media);
    }
    if (nota_presentada<5){
        printf ("Nota media de asignaturas presentadas: SUSPENSO (%.1f)",nota_presentada);
    }else if (5<=nota_presentada && nota_presentada<=6.9){
        printf ("Nota media de asignaturas presentadas: APROBADO (%.1f)",nota_presentada);
    }else if (7<=nota_presentada && nota_presentada<=8.9){
        printf ("Nota media de asignaturas presentadas: NOTABLE (%.1f)",nota_presentada);
    }else if (9<=nota_presentada){
        printf ("Nota media de asignaturas presentadas: SOBRESALIENTE (%.1f)",nota_presentada);
    }

}

int main() {
    float notas[MAX], nota_media=0, nota_presentadas=0;
    int asignaturas=0;

    for (int i=0; i<MAX; i++){
        printf("Calificacion asignatura %d(formato X.X, 0 para no presentado):", i+1);
        scanf ("%f", &notas[i]);
        if (notas[i]>10 && notas[i]<0){
            i--;
            printf("Calificacion de asignatura no valida\n");
        }else{
            nota_media+=notas[i];
            if (notas[i]!=0){
                asignaturas++;
                nota_presentadas+=notas[i];
            }
        }
    }

    nota_media=(nota_media/MAX);
    nota_presentadas=(nota_presentadas/(float)asignaturas);

    media (nota_media, nota_presentadas);

    return 0;
}
