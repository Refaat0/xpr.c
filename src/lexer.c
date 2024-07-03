#include "../include/array_list.h"
#include "../include/stack.h"
#include "../include/token.h"
#include "../include/lexer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

ArrayList *lex(char *source) {
    ArrayList *tokens = list_create();

    while (*source) {
        switch (*source) {
            case '(':
                list_append(tokens, token_create(LeftParenthesis, '(', 0));
                break;
            case ')':
                list_append(tokens, token_create(RightParenthesis, ')', 0));
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                list_append(tokens, token_create(Operator, *source, 0));
                break;
            default:
                // todo: account for, floating point operands, and signed operands
                if (_is_operand(*source)) {
                    int r = 0;
                    while (_is_operand(*source)) {
                        r = r * 10 + (*source - '0');
                       *source++;
                    }
                    *source--;

                    list_append(tokens, token_create(Operand, '\0', r));
                }
                break;
        }

        *source++;
    }

    return tokens;
}

// the worst function in this entire project 
bool is_valid_infix_expression(char *source, char *error_message, unsigned int error_message_size) {
    unsigned int count_right_parenthesis = 0, count_left_parenthesis = 0, count_operators = 0, count_operands = 0;

    //
    ArrayList *tokens = lex(source);

    //
    for (int i = 0; i < tokens->size; i++) {
        Token *current_token = list_get(tokens, i);

        switch (current_token->token_type) {
            case Operator:
                count_operators++;
                break;
            case Operand:
                count_operands++;
                break;
            case RightParenthesis:
                count_right_parenthesis++;
                break;
            case LeftParenthesis:
                count_left_parenthesis++;
                break;
        }
    }

    if (list_is_empty(tokens)) {
        snprintf(error_message, error_message_size, "Error: Expressions should be at least one characters long");
        return false;
    }

    if (count_operands <= 1) {
        snprintf(error_message, error_message_size, "Error: The expression does not contain enough operands");
        return false;
    }

    if (count_operators <= 0) {
        snprintf(error_message, error_message_size, "Error: The expression does not contain enough operators");
        return false;
    }

    if (count_operators >= count_operands) {
        snprintf(error_message, error_message_size, "Error: The expression contains too many operators");
        return false;
    }


    if (count_left_parenthesis != count_right_parenthesis) {
        snprintf(error_message, error_message_size, "Error: The expression contains unbalanced parenthesis");
        return false;
    }

    return true;
}

bool _is_operator(char c) {
    switch (c) {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return true;
    }

    return false;
}

bool _is_operand(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }

    return false;
}

float _string_to_float(char *string) {
    float f = 0;
    return f;
}
