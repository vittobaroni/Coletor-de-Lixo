# Define variáveis para facilitar a manutenção
CC = cl
TARGET = meu_exemplo.exe
SOURCES = meu_exemplo.c
OBJECTS = $(SOURCES:.c=.obj)

# Caminhos para a biblioteca BDWGC
GC_INCLUDE_DIR = C:\trabalho\gc-git\include
GC_LIB_DIR = C:\trabalho\gc-git\out\Release
GC_LIB = gc.lib

# Opções do Compilador: /EHsc é uma boa prática, /c diz para apenas compilar (sem linkar)
CFLAGS = /EHsc /I $(GC_INCLUDE_DIR) /Zi

# --- REGRAS DE BUILD ---

# Regra padrão: o que fazer quando digitamos "nmake"
all: $(TARGET)

# Regra para LINKAR o executável a partir dos arquivos objeto
# Esta regra so E executada depois que os arquivos .obj estiverem prontos
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) /link /LIBPATH:$(GC_LIB_DIR) $(GC_LIB)

# Regra para COMPILAR os arquivos .c em arquivos .obj
# É uma regra genérica que ensina o nmake a transformar qualquer .c em um .obj
.c.obj:
	$(CC) $(CFLAGS) /c $<

# Regra para limpar os arquivos gerados
clean:
	del *.obj *.exe *.pdb *.ilk /q