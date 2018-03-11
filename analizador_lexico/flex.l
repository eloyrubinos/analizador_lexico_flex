%{
#include "TablaSimbolos.h"
#include "Definiciones.h"
#include "gestionErrores.h"

typedef struct {
    short tipo;
    char* lexema;
}compLex;

%}

/* No proporciono definción para la función yywrap. */
%option noyywrap
 /* Para contar las líneas. */
%option yylineno

/* Definición de expresiones tal y como se declaran en la especificación del lenguaje. */

NEWLINE                       \n
ESPACIO                       [ ]
SEPARADOR                     (\t|\r|{ESPACIO})+
UNICODE_CHAR                  .
UNICODE_LETTER                [A-Za-z]
LETTER                        {UNICODE_LETTER}|_
DECIMAL_DIGIT                 [0-9]
OCTAL_DIGIT                   [0-7]
HEX_DIGIT                     [0-9A-Fa-f]
UNICODE_DIGIT                 {DECIMAL_DIGIT}
SEMICOLON                     ;

DECIMAL_LIT                   [1-9]{DECIMAL_DIGIT}*
OCTAL_LIT                     0{OCTAL_DIGIT}*
HEX_LIT                       0[xX]{HEX_DIGIT}+
INT_LIT                       {DECIMAL_LIT}|{OCTAL_LIT}|{HEX_LIT}

DECIMALS                      {DECIMAL_DIGIT}+
EXPONENT                      [eE][+-]?{DECIMALS}
FLOAT_LIT                     {DECIMALS}\.{DECIMALS}?{EXPONENT}?|{DECIMALS}{EXPONENT}|\.{DECIMALS}{EXPONENT}?

IMAGINARY_LIT                 {DECIMALS}i|{FLOAT_LIT}i

IDENTIFIER                    {LETTER}({LETTER}|{UNICODE_DIGIT})*

OP_PUNC                       [+*/%&|^,.:!><=(){}[\]-]|{SEMICOLON}
OP_ASIG                       :=
OP_FLECHA                     <-
OP_SUMA_CMPX                  \+=

ESCAPED_CHAR                  \\[abfnrtv'"\\]
BIG_U_VALUE                   \\U{HEX_DIGIT}{8}
LITTLE_U_VALUE                \\u{HEX_DIGIT}{4}
HEX_BYTE_VALUE                \\x{HEX_DIGIT}{2}
OCTAL_BYTE_VALUE              \\{OCTAL_DIGIT}{3}
BYTE_VALUE                    {OCTAL_BYTE_VALUE}|{HEX_BYTE_VALUE}
UNICODE_VALUE                 {UNICODE_CHAR}|{LITTLE_U_VALUE}|{BIG_U_VALUE}|{ESCAPED_CHAR}

INTERPRETED_STRING_LIT        ["]({UNICODE_VALUE}|{BYTE_VALUE})+["]
RAW_STRING_LIT                [`]({UNICODE_CHAR}|{NEWLINE})+[`]
STRING_LIT                    {RAW_STRING_LIT}|{INTERPRETED_STRING_LIT}

COMM_IN                       \/\/.*
COMM_MULT                     \/\*(.|{NEWLINE})*\*\/

%%

{NEWLINE}                       return ((int) *yytext);
{SEPARADOR}                     
{COMM_IN}
{COMM_MULT}
{IDENTIFIER}                    return (_IDENTIFICADOR);
{STRING_LIT}                    return (_STRING);
{INT_LIT}                       return (_ENTERO);
{FLOAT_LIT}                     return (_REAL);
{IMAGINARY_LIT}                 return (_IMAGINARIO);
{OP_ASIG}                       return (_OP_ASIG);
{OP_FLECHA}                     return (_OP_FLECHA);
{OP_SUMA_CMPX}                  return (_OP_SUMA_CMPX);
{OP_PUNC}                       return ((int) *yytext);
.                                return (-1);
<<EOF>>                       {yyterminate();}

%%

void leer(char* file){
    if((yyin = fopen(file, "r")) == NULL) errorIO("Fallo al abrir el archivo fuente.\n"); 
}

int siguiente_Lexema(compLex *lex){
    lex->tipo = yylex();
    if(lex->lexema != NULL){
	free(lex->lexema);
	lex->lexema = NULL;
    }
    lex->lexema = strdup(yytext);

    if(lex->tipo == _IDENTIFICADOR) insertarEnTabla(lex->lexema, 0);
    else if(lex->tipo == -1) errorLexico(yylineno);

    return lex->tipo;
}

void cerrar(){
    fclose(yyin);
}
