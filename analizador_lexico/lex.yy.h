typedef struct {
    short tipo;
    char* lexema;
}compLex;

void leer(char* file);
void cerrar();
int siguiente_Lexema(compLex *lex);
