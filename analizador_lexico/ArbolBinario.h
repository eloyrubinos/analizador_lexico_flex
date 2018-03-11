////////////////////////////////////////////////////////////////
typedef struct {char* lexema; short tipo, bloque;} elemento;

typedef char* indice;
////////////////////////////////////////////////////////////////
		
typedef void *abb; //tipo opaco

void crea(abb *A);
void destruye(abb *A);
unsigned esVacio(abb A);
void inserta(abb *A, char* cadena, short tipo, short bloque);
short busca_e_inserta(abb *A, char* cadena, short bloque);
void imprimirArbol(abb *A);
/*tipoelem suprime_min(abb *A);
void suprime(abb *A,tipoelem E);
unsigned esMiembro(abb A, tipoelem E);
abb izq(abb A);
abb der(abb A);
void info(abb A, tipoelem *E);
void buscanodo(abb A, tipoclave cl, tipoelem *nodo);
void modifica(abb *A, tipoclave cl, tipoelem nodo);*/
