#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Definiciones.h"

////////////////////////////////////////////////////////////
typedef struct {char* lexema; short tipo, bloque;} elemento;
typedef char* indice;
////////////////////////////////////////////////////////////////

struct celda {
    elemento info;
    struct celda *izq, *der;
};

typedef struct celda * abb;

void crea(abb *A) {
    *A = NULL;
}

void destruye(abb *A) {
    if (*A != NULL) {
        destruye(&(*A)->izq);
        destruye(&(*A)->der);
        free(*A);
        *A = NULL;
    }
}

unsigned esVacio(abb A) {
    return A == NULL;
}

void inserta(abb *A, char* cadena, short tipo, short bloque) {
    if (esVacio(*A)) {
        *A = (abb) malloc(sizeof (struct celda));
        (*A)->info.lexema = (char*) malloc(9 * sizeof(char));
        strncat((*A)->info.lexema, cadena, strlen(cadena));
        (*A)->info.tipo = tipo;
        (*A)->info.bloque = bloque;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    } else if (strcmp(cadena,(*A)->info.lexema)<0)
        inserta(&(*A)->izq, cadena, tipo, bloque);
    else
        inserta(&(*A)->der, cadena, tipo, bloque);
}

short busca_e_inserta(abb *A, char* cadena, short bloque){
    if (esVacio(*A)){
        *A = (abb) malloc(sizeof (struct celda));
        (*A)->info.lexema = (char*) malloc(strlen(cadena) * sizeof(char));
        (*A)->info.lexema[0] = '\0';
        strncat((*A)->info.lexema, cadena, strlen(cadena));
        (*A)->info.tipo = _IDENTIFICADOR;
        (*A)->info.bloque = bloque;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        return _IDENTIFICADOR;
    }
    else if (strcmp(cadena,(*A)->info.lexema)==0){
        return ((*A)->info.tipo);
    }
    else if (strcmp(cadena,(*A)->info.lexema)<0){
        return (busca_e_inserta(&(*A)->izq, cadena, bloque));
    }
    else{
        return (busca_e_inserta(&(*A)->der, cadena, bloque));
    }
}

void imprimirArbol(abb *A){
    short n, i;
    if(!esVacio(*A)){
        if(&(*A)->izq != NULL)
            imprimirArbol(&(*A)->izq);
        
        //info(arbol,&eAux);
        printf("Lexema: %s", (*A)->info.lexema);
        for(i = 0; i < 12 - strlen((*A)->info.lexema); i++){
            printf(" ");
        }
        printf("Componente lexico: %hd", (*A)->info.tipo);
        if((*A)->info.tipo < 10) n = 1;
        else if((*A)->info.tipo < 100) n = 2;
        else if((*A)->info.tipo < 1000) n = 3;
        for(i = 0; i < 11 - n; i++){
            printf(" ");
        }
        printf("Bloque: %hd\n", (*A)->info.bloque);
        
        if(&(*A)->der != NULL)
            imprimirArbol(&(*A)->der); 
    }
}

/*
elemento suprime_min(abb *A) {
    abb aux; 
    elemento ele;
    if ((*A)->izq == NULL) {
        ele = (*A)->info;
        aux = *A;
        *A = (*A)->der;
        free(aux);
        return ele;
    } else
        return suprime_min(&(*A)->izq);

}

void suprime(abb *A, elemento E) {
    abb aux;
    if (*A != NULL) {
        if (strcmp(E.apeNom,(*A)->info.apeNom)<0)
            suprime(&(*A)->izq, E);
        else if (strcmp(E.apeNom,(*A)->info.apeNom)>0)
            suprime(&(*A)->der, E);
        else if ((*A)->izq == NULL && (*A)->der == NULL) {
            free(*A);
            *A = NULL;
        } else if ((*A)->izq == NULL) {
            aux = *A;
            *A = (*A)->der;
            free(aux);
        } else if ((*A)->der == NULL) {
            aux = *A;
            *A = (*A)->izq;
            free(aux);
        } else
            (*A)->info = suprime_min(&(*A)->der);

    }
}

unsigned esMiembro(abb A, elemento E) {
    if (esVacio(A))
        return 0;
    else if (strcmp(E.apeNom,A->info.apeNom)==0)
        return 1;
    else if (strcmp(E.apeNom,A->info.apeNom)<0)
        return esMiembro(A->izq, E);
    else
        return esMiembro(A->der, E);
}

void info(abb A, elemento *E) {
    *E = A->info;
}

abb izq(abb A) {
    return A->izq;
}

abb der(abb A) {
    return A->der;
}

void buscanodo(abb A, index cl, elemento *nodo) {
    if (esVacio(A))
        printf("Clave inexistente\n");
    else if (strcmp(cl,A->info.apeNom)==0)
        *nodo = A->info;
    else if (strcmp(cl,A->info.apeNom)<0)
        buscanodo(izq(A), cl, nodo);
    else
        buscanodo(der(A), cl, nodo);
}

void modifica(abb *A, index cl, elemento nodo) {
    if (esVacio(*A)) {
        printf("Clave inexistente\n");
    } else if (strcmp(cl,(*A)->info.apeNom)==0)
        (*A)->info = nodo;
    else if (strcmp(cl,(*A)->info.apeNom)<0)
        modifica(&(*A)->izq, cl, nodo);
    else
        modifica(&(*A)->der, cl, nodo);
}
*/