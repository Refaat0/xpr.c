CC=gcc
CFLAGS=-lm

compile: src/main.c src/array_list.c src/stack.c src/token.c src/parser.c src/lexer.c src/evaluator.c src/error.c
	@echo "Compiling..."
	$(CC) -o xpr src/main.c src/array_list.c src/stack.c src/token.c src/parser.c src/lexer.c src/evaluator.c src/error.c $(CFLAGS)
