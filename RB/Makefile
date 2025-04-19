# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -O3 -g

# Arquivos-fonte e alvo
SRCS = redBlack.c myrb.c
OBJS = $(SRCS:.c=.o)
	TARGET = myrb

# Regra padrão
all: $(TARGET)

# Como compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para .o a partir de .c
%.o: %.c redBlack.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

