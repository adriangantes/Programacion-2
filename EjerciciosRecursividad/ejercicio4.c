#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

typedef struct{
    char dni[10];
    char nombre[20];
    char apellido1[20];
    char apellido2[20];
    int telefono;
    float sueldo;
}tTrabajador;

typedef struct {
    char denominacion[20];
    tTrabajador trabajador[30];
    int num_trabajadores;
}tCentro;

typedef struct {
    tCentro centro[40];
    int num_centros;
}tEmpresa;

void nuevo_centro (tEmpresa *e){

    if (e->num_centros<40){
        tCentro c;
        char p;
        c.num_trabajadores=0;

        printf ("Nombre del centro de trabajo: ");
        scanf ("%s", c.denominacion);

        do{
            printf ("\nVas a introducir un nuevo trabajador?\nTeclea s(i) o n(o): ");
            scanf ("%s", &p);

            if (p == 's'){
                tTrabajador a;

                printf ("DNI del trabajador: ");
                scanf ("%s", a.dni);

                printf ("Nombre y apellidos del trabajador: ");
                scanf ("%s %s %s", a.nombre, a.apellido1, a.apellido2);

                printf ("Telefono del trabajador: ");
                scanf ("%d", &a.telefono);

                printf ("Sueldo del trabajador: ");
                scanf ("%f", &a.sueldo);

                c.trabajador[c.num_trabajadores] = a;
                c.num_trabajadores++;
            }
        } while (p == 's');

        e->centro[e->num_centros]= c;
        e->num_centros++;
    }
}

void mostrar_centros (tEmpresa e){

    if (e.num_centros != 0){
        printf ("Centros de trabajo:\n");
        for (int i=0; i<e.num_centros; i++){
            printf ("%d. %s: %d trabajadores\n", i+1, e.centro[i].denominacion, e.centro[i].num_trabajadores);
        }
    }else{
        printf ("No hay centros de trabajo guardados\n");
    }

    printf ("\nPulsa cualquier tecla para continuar");
    getch();
}

void mostrar_trabajadores (tEmpresa e){

    if (e.num_centros != 0){
        int num;
        printf ("Cual de los siguientes centros desea observar?\n");
        for (int i=0; i<e.num_centros; i++){
            printf ("\t%d. %s\n", i+1, e.centro[i].denominacion);
        }
        do{
            num = getch () - '0';
            if (num<1 || num>e.num_centros){
                printf ("\nNo existe el centro seleccionado");
            }
        }while (num<1 || num>e.num_centros);
        --num;
        system ("cls");

        if (e.centro[num].num_trabajadores != 0){
            printf ("\nEmpleados del centro:\n");

            for ( int i=0 ; i<e.centro[num].num_trabajadores ; i++ ){
                printf ("\n");
                printf("%d\tDNI: %s\n", i+1, e.centro[num].trabajador[i].dni);
                printf("\tNombre: %s\tApellidos: %s %s\n", e.centro[num].trabajador[i].nombre,
                       e.centro[num].trabajador[i].apellido1, e.centro[num].trabajador[i].apellido2);
                printf("\tTelefono: %d\n", e.centro[num].trabajador[i].telefono);
                printf("\tSueldo: %.2f\n", e.centro[num].trabajador[i].sueldo);

            }

        }else{
            printf ("No hay trabajadores guardados en este centro\n");
        }

    }else{
        printf ("No hay centros de trabajo guardados\n");
    }

    printf ("\nPulsa cualquier tecla para continuar");
    getch();
}

void borrar_centro (tEmpresa *e){

    if (e->num_centros != 0){
        int num;
        printf ("Cual de los siguientes centros desea borrar?\n");
        for (int i=0; i<e->num_centros; i++){
            printf ("\t%d. %s\n", i+1, e->centro[i].denominacion);
        }
        do{
            num = getch () - '0';
            if (num<1 || num>e->num_centros){
                printf ("\nNo existe el centro seleccionado");
            }
        }while (num<1 || num>e->num_centros);
        --num;
        system ("cls");

        while (num < e->num_centros){
            e->centro[num]=e->centro[num+1];
            ++num;
        }
        --e->num_centros;

    }else{
        printf ("No hay centros de trabajo guardados");
    }
}

void iniciar_empresa (tEmpresa *e){
    e->num_centros=0;
}

void menu (){
    printf("Programa de administracion de centros de trabajo:\n");
    printf("--------------------------------------------------\n\n");
    printf ("Introduce el numero de la opcion que desea:\n");
    printf ("\t1. Nuevo centro\n");
    printf ("\t2. Mostrar centros\n");
    printf ("\t3. Mostrar trabajadores de un centro\n");
    printf ("\t4. Eliminar centro\n");
    printf ("\t0. Salir del programa\n");
}

int main() {
    tEmpresa e;
    int num;

    iniciar_empresa (&e);
    system ("cls");

    do{
        menu();
        num = getch () - '0';
        system ("cls");

        if (num==1){
            nuevo_centro(&e);
        }else if (num==2){
            mostrar_centros(e);
        }else if (num==3){
            mostrar_trabajadores(e);
        }else if (num==4){
            borrar_centro(&e);
        }

        system ("cls");
    }while (num>=1 && num<=4);

    printf ("\nSaliendo del programa...\n\n");
    sleep(2);

    return 0;
}
