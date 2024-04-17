#ifndef LEXER_H
#define LEXER_H

#include "../include/array_list.h"
#include "../include/token.h"
#include "../include/error.h"

/**
 * @brief   this function scans through the provided source string and classifies each character into tokens
 *          specified by the TokenType enumerator in token.h. It creates a Token structure for each character,
 *          and appends it to an ArrayList which is then returned to the caller.
 *          note: it is the callers responsiblity to free the ArrayList returned after it has been used
 * 
 * @param  source a string literal representing a mathematical expression in infix notation
 * @return an ArrayList containing a sequence of Tokens extracted from the expression
*/
ArrayList *lex(char *source);

/**
 * @brief   ...
 * @param   ...
 * @return  ...
*/
bool is_valid_infix_expression(char *source, char *error_message, unsigned int error_message_size);

/**
 * 
*/
bool _is_operator(char c);

/**
 * 
*/
bool _is_operand(char c);

/**
 * 
*/
float _string_to_float(char *string);


#endif
