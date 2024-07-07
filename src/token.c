#include "../include/token.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

Token *token_create(TokenType token_type, char symbol, float number) {
    Token *token = malloc(sizeof(Token));
    if (token == NULL) {
        fprintf(stderr, "Faile to allocate memory for a Token structure\n");
        return NULL;
    }

    token->token_type = token_type;
    token->symbol     = symbol;
    token->number     = number;

    return token;
}

bool token_destroy(Token *token) {
    free(token);
}

void token_print(Token *token) {
    switch (token->token_type){
        case Operand:
            printf("Token.Operand=%d\n", token->number);
            break;
        case Operator:
            printf("Token.Operator=%c\n", token->symbol);
            break;
        case LeftParenthesis:
            printf("Token.LeftParenthesis=%c\n", token->symbol);
            break;
        case RightParenthesis:
            printf("Token.RightParenthesis=%c\n", token->symbol);
            break;
    }
}