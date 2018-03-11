#include <stdlib.h>
#include <stdio.h>

// Cuando hay un error en el sistema de entrada, imprimo un mensaje y cierro el programa.
void errorIO(char* mensaje){
    printf("%s", mensaje);
    exit(0);
}

// Cuando me encuentre un error léxico puedo llamar a esta función para indicar la línea y el carácter que han dado el problema.
void errorLexico(int linea){
    printf("\nSe ha detectado un error léxico en la linea: %d\n", linea);
}
