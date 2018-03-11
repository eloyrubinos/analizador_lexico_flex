CC= gcc -Wall
HEADER_FILES_DIR = .
INCLUDES = -I $(HEADER_FILES_DIR)
MAIN= anaLex
SRCS = main.c lex.yy.c AnalizadorSintactico.c ArbolBinario.c TablaSimbolos.c gestionErrores.c
DEPS = $(HEADER_FILES_DIR)/lex.yy.h AnalizadorSintactico.h ArbolBinario.h Definiciones.h TablaSimbolos.h gestionErrores.h
OBJS = $(SRCS:.c=.o)
$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)
	rm -f *.o *~
%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)
cleanall: clean
	rm -f $(MAIN)
clean:
	rm -f *.o *~
