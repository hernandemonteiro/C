# Nome do executável
TARGET = main.out

# Compilador
CC = gcc

# Arquivos de origem
SRCS = main.c

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Limpar os arquivos compilados
clean:
	rm -f $(TARGET)