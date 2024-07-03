#include "../include/array_list.h"
#include "../include/stack.h"
#include "../include/token.h"
#include "../include/lexer.h"
#include "../include/parser.h"
#include <math.h>

int evaluate_postfix_expression(ArrayList *tokens) {
    Stack *operands = stack_create();
    int result = 0;

    for (int i = 0; i < tokens->size; i++) {
        Token *current_token = (Token*) list_get(tokens, i);

        switch (current_token->token_type) {
            case Operand:
                stack_push(operands, current_token);
                break;

            case Operator:{
                int value_a = ((Token*)stack_pop(operands))->number;
                int value_b = ((Token*)stack_pop(operands))->number;

                switch (current_token->symbol) {
                    case '^':
                        result = pow(value_b, value_a);
                        break;
                    case '*':
                        result = value_b*value_a;
                        break;
                    case '/':
                        result = value_b/value_a;
                        break;
                    case '+':
                        result = value_b+value_a;
                        break;
                    case '-':
                        result = value_b-value_a;
                        break;
                }

                stack_push(operands, token_create(Operand, '\0', result));
                
                break;
            }
        }
    }


    // todo: return token & destroy operands stack (mem leak)
    return ((Token*)stack_peek(operands))->number;
}

int evaluate_infix_expression(char *infix_expression) {
    // declare & initialize an ArrayList of tokens ordered in infix notation
    ArrayList *tokens_infix_notation = lex(infix_expression);

    // delcare & initialize an ArrayList of tokens ordered in postfix notation
    ArrayList *tokens_postfix_notation = infix_to_postfix(tokens_infix_notation);

    // declare & initialize an Integer of which its value is the evaluated postfix expression
    int e = evaluate_postfix_expression(tokens_postfix_notation);

    // destroy all tokens in the tokens ArrayList
    for (int i = 0; i  < tokens_infix_notation->size; i++) {
        Token *current_token = list_get(tokens_infix_notation, i);
        token_destroy(current_token);
    }

    // destroy the tokens ArrayList
    list_destroy(tokens_infix_notation);
    list_destroy(tokens_postfix_notation);

    return e;
}