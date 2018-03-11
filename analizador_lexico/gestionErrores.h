// Función que marca el fin del programa y avisa de que se ha producido un error de lectura/escritura.
void errorIO();
// Cuando me encuentre un error léxico puedo llamar a esta función para indicar la línea y el carácter que han dado el problema.
void errorLexico(int linea);