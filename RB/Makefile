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
clear:
	rm -f $(OBJS) $(TARGET) Testers/*.temp

# Rodar todos os testes
test: $(TARGET)
	@echo "🔍 Rodando testes..."
	@for i in 1 2 3 4; do \
		echo "Testando caso $$i..."; \
		./$(TARGET) < Testers/test$$i.in > Testers/test$$i.temp; \
		if diff -q Testers/teste$$i.out Testers/test$$i.temp > /dev/null; then \
		echo "✅ Teste $$i: OK"; \
		else \
		echo "❌ Teste $$i: FALHOU"; \
		echo "  Diferenças:"; \
		diff -y --suppress-common-lines Testers/teste$$i.out Testers/test$$i.temp || true; \
		fi; \
		done
