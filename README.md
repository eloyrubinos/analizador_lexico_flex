# analizador_lexico_flex

###### IDE
> Ninguno

###### Conocimientos principales aplicados
- C
- Teoría de compiladores
- Go
- Árboles binarios de búsqueda
- Expresiones regulares
- **[Flex](https://github.com/westes/flex)**

###### Descripción
Este proyecto es equivalente a mi otro [analizador_lexico](https://github.com/eloyrubinos/analizador_lexico) pero usando la herramienta Flex para generar el analizador a partir de la descripción formal del lenguaje.

Es decir, en el proyecto anteriormente mencionado quitamos el analizador léxico propio y creamos un [archivo de definción de flex](./analizador_lexico/flex.l) que compilamos con `flex --header-file="lex.yy.h" flex.l`. Los archivos generados deben llamarse, necesariamente, *lex.yy.c* y *lex.yy.h* y deben situarse en la misma carpeta que el resto del proyecto.

###### Ejecución
[Instrucciones](./README).

Solo se ha probado en **Linux**.

###### Salida
La salida generada puede consultarse [aquí](./salida.txt).

###### Posibles mejoras
- Ampliarlo para que identifique todos los componentes léxicos del lenguaje Go.
