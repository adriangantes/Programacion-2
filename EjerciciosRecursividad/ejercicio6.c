#include <stdio.h>
#include <string.h>

int divide (int n1, int n2){
    if (n1<n2){
        return 0;
    }else{
        return divide(n1-n2, n2)+1;
    }
}

void inverso (int n){
    if (n<10){
        printf ("%d", n);
    }else{
        printf("%d",n%10);
        inverso(n/10);
    }
}

int ocurrences (int n, int array[5], int ini, int fin){
    if (ini > fin){
        return 0;
    }else if (n == array[ini]){
        return 1+ocurrences(n, array, ini+1, fin);
    }else{
        return ocurrences(n, array, ini+1, fin);
    }
}

void BinaryConversion (int n){
    if (n>1){
        BinaryConversion(n/2);
        printf ("%d",n%2);
    }else{
        printf ("%d", n);
    }
}

int pascal(int i, int j) {
    if (j==0 || j==i) {
        return 1;
    }else{
        return (pascal(i-1,j-1)+pascal(i-1, j));
    }
}

int auxPalindromo(char *palabra, int ini, int fin){
    if (ini >= fin){
        return 1;
    }else if (palabra[ini] == palabra[fin]){
        auxPalindromo (palabra, ++ini, --fin);
    }else{
        return 0;
    }
}

int esPalindromo (char *palabra){
    return auxPalindromo(palabra, 0, strlen(palabra)-1);
}

int main() {
    int array[5]={1,2,3,4,2};
    char palabra [20];


    printf ("\nResultado de la division: %d",divide (20, 5));
    printf ("\nInverso del numero 723: ");
    inverso(723);
    printf ("\nVeces que aparece el 2 en el array: %d", ocurrences(2, array, 0, 5));
    printf ("\nNumero 42 en binario: ");
    BinaryConversion(42);
    printf ("\nEl numero de pascal en la posicion i=4 y j=2: %d", pascal (4,2));
    printf ("\n\nIntroduce una palabra: ");
    scanf ("%s", palabra);
    printf ("Son palindromos? %s", esPalindromo(palabra)==1 ? "Si" : "No");


    printf("\n");
    return 0;
}
