#
# Arquivo de Makefile
#

# Nome do projeto
PROJ_NAME=dft_matrix.x

# Arquivos de código fonte .c
C_SOURCE=$(wildcard *.c)

# Arquivos de cabeçalho .h
H_SOURCE=$(wildcard *.h)

# Arquivo do octave
OCTAVE_SOURCE=$(wildcard *.m)

# Arquivos objeto .o
OBJ=$(C_SOURCE:.c=.o)

# Compilador
CC=gcc

# Flags para o compilador
CC_FLAGS=-c \
	 -O \
	 -W \
	 -Wall \
	 -pedantic \
	 -std=c99 \
	 -Wpedantic

LIBS=-lm

#
# Compilação e Linkagem
#

graph: 
	@echo " "
	@mkdir -p ./results
	@octave $(OCTAVE_SOURCE)
	mv *.aux *.log *.tex *.pdf ./results
	@echo " "

# 1º Passo: Início do processo de build

debug: CC_FLAGS+=-DDEBUG_MODE
debug: CC_FLAGS+=-g
debug: $(PROJ_NAME)

release: $(PROJ_NAME)

# 3º Passo: Linkagem
$(PROJ_NAME):	$(OBJ)
	@echo " "
	@echo "2 - Starting program linking..."
	$(CC) $^ -o $@ $(LIBS)
	@echo " "
	@echo "Program building completed."
	@echo " "

%.o:	%.c %.h
	@echo " "
	$(CC) $(CC_FLAGS) $< -o $@

# 2º Passo: Compilação
main.o:	main.c $(H_SOURCE)
	@echo " "
	@echo "## Starting program building:"
	@echo "1 - Starting program compiling..."
	$(CC) $(CC_FLAGS) $< -o $@
	@echo " "

# Processo de Limpeza
clean:
	@echo " "
	@echo "Removing object files and executable files..."
	rm *.o *.txt $(PROJ_NAME)
	rm -rf ./results
	@echo "Cleaning Completed."
	@echo " "

# Processo de execução do programa
run:
	@echo " "
	@./$(PROJ_NAME)
	@echo " "

all: release graph

.PHONY:	build clean run graph

