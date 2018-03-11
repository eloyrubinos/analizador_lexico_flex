#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArbolBinario.h"
#include "gestionErrores.h"

/* Tamaño de la cadena en que almaceno las lecturas de lexemas de la tabla de símbolos. Sé que el lexema más grande es de longitud 7
   porque el archivo de definiciones es un fichero estático que puedo comprobar en todo momento.
   Si en algún momento añadiese un lexema más grande, es fácil venir aquí y cambiar esta constante.*/
#define TAM 8 

abb tabla; // Mi tabla de símbolos. Un árbol binario.

/* Creo la tabla de símbolos y la relleno con las palabras reservadas del lenguaje. */
void iniciarTabla(){
    size_t len = 100; // Longitud de la variable en que voy a almacenar las líneas leídas.
    char* line = (char*) malloc(len * sizeof(char)); // Variable en que almaceno líneas completas del fichero de definiciones.
    ssize_t lectura = 1; // Caracteres leídos por la función getline(), o EOF cuando llega al final del fichero o se produce algún error.
    char* lexemaDefs = (char*) malloc(TAM * sizeof(char)); // Variable para almacenar los lexemas cuando los recibo.  
    char* macro = (char*) malloc((TAM+1) * sizeof(char)); // Variable para almacenar las macros cuando las recibo. Tengo que almacenarlas aunque me den igual para leer con sscanf porque no son iguales siempre.
    int args; // Variable para almacenar el número de argumentos almacenados por sscanf().
    short tipoDefs; // Variable para almacenar el componente léxico de las palabras reservadas.
    crea(&tabla);  // Inicializo la tabla de símbolos.
    
    FILE *defs;
    if((defs = fopen("Definiciones.h", "r")) == NULL){ // Intento abrir el documento de definiciones.
        errorIO("\nFallo al abrir el fichero de definiciones.\n");
    }
    else{ // Si se abre con éxito:
        while((lectura = getline(&line, &len, defs)) != -1){
            if((args = sscanf(line, "#define %s %hd //%s", macro, &tipoDefs, lexemaDefs)) < 3) break;
            inserta(&tabla, lexemaDefs, tipoDefs, 0);
        }
        if(lectura == -1) errorIO("Fallo al leer el fichero de definiciones.\n");
    }
    if(line != NULL){
        free(line);
        line = NULL;
    }
    if(lexemaDefs != NULL){
        free(lexemaDefs);
        lexemaDefs = NULL;
    }
    if(macro != NULL){
        free(macro);
        macro = NULL;
    }
}

/* Función para buscar en la tabla e insertar cuando sea necesario: devuelve _IDENTIFICADOR o el componente léxico de aquello con lo que el argumento haya coincidido. */
short insertarEnTabla(char* cadena, short bloque){
    return (busca_e_inserta(&tabla, cadena, bloque));
}

/* Función para imprimir la tabla de símbolos. */
void imprimirTabla(){
    printf("\n---------------------Tabla de simbolos---------------------\n");
    imprimirArbol(&tabla);
    printf("\n\n");
}

/* Función para liberar la memoria de la tabla de símbolos. */
void eliminarTabla(){
    destruye(&tabla);
}
