#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../include/array_list.h"

/**
 * @brief   This function evaluates a postfix expression using a stack-based algorithm.
 *          note: It is the callers responsiblity to free the ArrayList provided in the function parameters after it has been used
 * 
 * @param   tokens An ArrayList containing a sequence of tokens in postfix notation
 * @return  The result of the expression evaluation.
*/
float evaluate_postfix_expression(ArrayList *tokens);

/**
 * @brief   this function...
 *          note:
 * 
 * @param   infix_expression ...
 * @return  ...
*/
float evaluate_infix_expression(char *infix_expression);

#endif
