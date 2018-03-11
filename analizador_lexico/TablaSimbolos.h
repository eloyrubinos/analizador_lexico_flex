/* Función que crea la tabla de símbolos y la rellena con las palabras reservadas del lenguaje. */
void iniciarTabla();
/* Función para buscar en la tabla e insertar cuando sea necesario: devuelve _IDENTIFICADOR o el componente léxico de aquello con lo que el argumento haya coincidido. */
short insertarEnTabla(char* cadena, short bloque);
/* Función para imprimir la tabla de símbolos. */
void imprimirTabla();
/* Función para liberar la memoria de la tabla de símbolos. */
void eliminarTabla();
