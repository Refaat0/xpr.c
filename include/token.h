#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>

typedef enum {
    Operand,
    Operator,
    LeftParenthesis,
    RightParenthesis
} TokenType;

typedef struct Token {
    TokenType token_type;
    char symbol;
    int  number;
} Token;

/**
 * @brief   This function returns an initialized Token structure
 *          note: It is the callers responsibility to free the Token after it has been used
 * 
 * @param   token_type An enumeration specified by TokenType
 * @param   symbol     A character representing a  mathematical operator
 * @param   number     An integer  representing an operand
 * @return  
*/
Token *token_create(TokenType token_type, char symbol, int number);

/**
 * @brief   This function frees memory allocated to a Token structure
 * @param   token A pointer to a Token structure
 * @return  A boolean of true if this operation is successful
*/
bool token_destroy(Token *token);

/**
 * @brief   This function prints a Token structure to the standard output
 * @param   token A pointer to a Token structure
*/
void token_print(Token *token);

#endif
