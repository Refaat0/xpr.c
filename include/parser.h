#ifndef PARSER_H
#define PARSER_H

#include "./array_list.h"
#include "./stack.h"
#include "./token.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief   This function takes a sequence of tokens in order of infix notation and returns a new ArrayList,
 *          in order of postfix notation. The conversion is accomplished by implementing The Shunting Yard aglorithm.
 * 
 *          note: It is the callers responsiblity to free the ArrayList provided in the function parameters after it has been used
 *          note: It is the callers responsiblity to free the ArrayList returned after it has been used
 *  * 
 * @param   tokens An ArrayList containing a sequence of tokens in infix notation
 * @return  An ArrayList containing a sequence of Tokens in postifx notation
*/
ArrayList *infix_to_postfix(ArrayList *tokens);

/**
 * @brief   This function is for future silliness
 * @param   tokens An ArrayList containing a sequence of tokens in postfix notation
 * @return  An Abstract Syntax Tree
*/
void *generate_ast(ArrayList *tokens);

/**
 * @brief   This function takes an operator symbol as input & returns its precedence value.
 *          This function currently only has support for the following characters:
 *          '^', '*'. '/*, '+', and '-'
 * 
 * @param   symbol A character representing a mathematical operator.
 * @return  The precedence value of the symbol
*/
int _precedence(char symbol);

/**
 * @brief   This function determines if an operator symbol has left associativity
 * @param   symbol A character representing a mathematical operator.
 * @return  A boolean of true if the provided symbol has left assosciativity
*/
bool _has_left_associativity(char symbol);

#endif
