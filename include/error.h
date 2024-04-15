#ifndef ERROR_H
#define ERROR_H

#define COLOUR_RED   "\x1b[31m"
#define COLOUR_RESET "\x1b[0m"

typedef enum {
    ERROR_UNBALANCED_PARENTHESIS,
    ERROR_NOT_ENOUGH_OPERANDS,
    ERROR_TOO_MANY_OPERATORS,
    ERROR_UNKNOWN_TOKEN,
    ERROR_ZERO_DIVISION,
    SUCCESS
} ErrorType;

/**
 * @brief This function prints pretty error message to the standard output
 * @param error_message ...
 * @param columns       ...
*/
void error_print(char *error_message, int columns);

/**
 * @brief This function handles 
 * @param error_type An error specified by ErrorType
*/
void error_handle(ErrorType error_type);

/**
 * @brief This function...
 * @param error_type
*/
char *error_to_string(ErrorType error_type);

/**
 * 
*/
void _silly(int columns);

#endif
