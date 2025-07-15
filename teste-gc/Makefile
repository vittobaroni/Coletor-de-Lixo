# Define o compilador
CC = cl

# --- VARIAVEIS DO PROJETO ---

# Programa 1
TARGET1 = meu_exemplo.exe
SOURCES1 = meu_exemplo.c
OBJECTS1 = $(SOURCES1:.c=.obj)

# Programa 2
TARGET2 = explicacao.exe
SOURCES2 = explicacao.c
OBJECTS2 = $(SOURCES2:.c=.obj)


# Caminhos e bibliotecas compartilhadas
GC_INCLUDE_DIR = C:\trabalho\gc-git\include
GC_LIB_DIR = C:\trabalho\gc-git\out\Release
GC_LIB = gc.lib

# Opções do Compilador e Linker
CFLAGS = /EHsc /I $(GC_INCLUDE_DIR) /Zi
LFLAGS = /link /LIBPATH:$(GC_LIB_DIR) $(GC_LIB)


# --- REGRAS DE BUILD ---

# O alvo padrão "all" agora constrói os dois programas.
# Se você digitar apenas "nmake", ele executará esta regra.
all: $(TARGET1) $(TARGET2)

# Regra para LINKAR o meu_exemplo.exe
$(TARGET1): $(OBJECTS1)
	$(CC) $(OBJECTS1) $(LFLAGS)

#Regra para linkar o explicacao.exe

$(TARGET2): $(OBJECTS2)
    $(CC) $(OBJECTS2) /link /LIBPATH:$(GC_LIB_DIR) $(GC_LIB)

# Regra genérica para COMPILAR qualquer arquivo .c em .obj
# Não precisamos mudar nada aqui, ela serve para os dois!
.c.obj:
	$(CC) $(CFLAGS) /c $<

# Regra "clean" atualizada para apagar os arquivos dos dois programas
clean:
	del *.obj $(TARGET1) $(TARGET2) *.pdb *.ilk /q
