#include <stdio.h>
#include <stdlib.h>
#include "AnalizadorSintactico.h"
#include "TablaSimbolos.h"
#include "lex.yy.h"

int main(int argc, char **argv) {

    /* Inicialización de todo el sistema. */
    leer(argv[1]); // Abro el archivo especificado por línea de comandos para analizar.
    iniciarTabla(); // Inicializo la tabla de símbolos.
    imprimirTabla(); // Imprimo la tabla de símbolos inicial.


    /* Ejecución del analizador sintáctico. */
    analizar(); // Ejecuto el analizador sintáctico.
    imprimirTabla(); // Imprimo la tabla de símbolos.

    /* Cierre y limpieza del sistema. */
    cerrar(); // Cierro el archivo analizado.
    eliminarTabla(); // Libero memoria de la tabla de símbolos.

    return (EXIT_SUCCESS);
}
