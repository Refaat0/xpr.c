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

                // todo: account for multi-digit operands, decimals, and signed operands
                if (_is_operand(*source)) {
                    list_append(tokens, token_create(Operand, '\0', *source - '0'));
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

    if (strlen(source) <= 0) {
        snprintf(error_message, error_message_size, "Error: Expressions should be at least one characters long");
        return false;
    }

    char source_start = *source;
    char source_end   = source[strlen(source) - 1];

    if (_is_operator(source_start) || _is_operator(source_end)) {
        snprintf(error_message, error_message_size, "Error: Operators can not be at the start or end of an expression");
        return false;
    }

    while (*source) {
        switch (*source) {
            case '(':
                count_left_parenthesis++;
                break;
            case ')':
                count_right_parenthesis++;
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                count_operators++;
                break;
            default:
                if (_is_operand(*source)) {
                    count_operands++;
                } else if (*source != ' ') {
                    snprintf(error_message, error_message_size, "Error: Unknown Token: '%c'", *source);
                    return false;
                }
                break;
        }

        *source++;
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
    return strtof(string, NULL);
}

