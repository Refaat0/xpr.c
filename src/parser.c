#include "../include/array_list.h"
#include "../include/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include "../include/token.h"
#include "../include/parser.h"

ArrayList *infix_to_postfix(ArrayList *tokens) {
    ArrayList *list  = list_create();
    Stack     *stack = stack_create();

    for (int i = 0; i < tokens->size; i++) {
        Token *current_token = (Token*)list_get(tokens, i);

        switch(current_token->token_type) {
            case LeftParenthesis:
                stack_push(stack, current_token);
                break;
            case RightParenthesis:
                while (!stack_is_empty(stack)) {
                    Token *top_token = (Token *)stack_peek(stack);
                    stack_pop(stack);
                    if (top_token->token_type == LeftParenthesis) {
                        break;
                    } else {
                        list_append(list, top_token);
                    } 
                }
            break;
            case Operator:
                while (!stack_is_empty(stack)) {
                    Token *top_operator = (Token *)stack_peek(stack);

                    if (top_operator->token_type != LeftParenthesis &&
                        (_precedence(top_operator->symbol) > _precedence(current_token->symbol) ||
                        (_precedence(top_operator->symbol) == _precedence(current_token->symbol) && _has_left_associativity(current_token->symbol)))) {
                        list_append(list, top_operator);
                        stack_pop(stack);
                    } else {
                        break;
                    }
                }
                stack_push(stack, current_token);
                break;
            case Operand:
                list_append(list, current_token);
                break;
            default:
                fprintf(stderr, "unexpected error");
                break;
        }
    }

    while (!stack_is_empty(stack)) {
        Token *token_top = (Token*)stack_peek(stack);   
        if (token_top->token_type != LeftParenthesis) {
            list_append(list, stack_peek(stack));
            stack_pop(stack);
        }        
    }

    stack_destroy(stack);

    return list;   
}

int _precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            fprintf(stderr, "unknown symbol for precedence comparision\n");
    }

}

bool _has_left_associativity(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}
