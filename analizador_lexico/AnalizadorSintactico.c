#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"

/* Solo tenemos una función, que recibe en bucle lexemas y componentes léxicos y los muestra por pantalla. */
void analizar(){
    compLex *lex; // Estructura en que guardo el lexema y el componente léxico.
    lex = (compLex*) malloc(sizeof(compLex)); // Le reservo memoria.
    lex->lexema = NULL; // Apunto el lexema a NULL para que no dé problemas.

    // Mientras el analizador léxico no reconozca el EOF, imprimo lo que me devuelve.
    while(siguiente_Lexema(lex)){
	if(lex->tipo == '\n') printf("\nLexema: \\n\nTipo: %hd\n", lex->tipo);
        else printf("\nLexema: %s\nTipo: %hd\n", lex->lexema, lex->tipo);
    }
    printf("\nFin del analisis lexico.\n");
    
    // Me aseguro de que no dejo la memoria dinámica de la estructura compLex sin liberar.
    if(lex->lexema != NULL){
        free(lex->lexema);
        lex->lexema = NULL;
    }
    free(lex);
    lex = NULL;
}
