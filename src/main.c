#include "../include/evaluator.h"
#include "../include/array_list.h"
#include "../include/parser.h"
#include "../include/error.h"
#include "../include/lexer.h"
#include "../include/stack.h"
#include "../include/token.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define PROGRAM_NAME "xpr.c"
#define PROGRAM_VERS "1.0"
#define INPUT_LENGTH 255

char error_message[255] = {'\0'};
char input[INPUT_LENGTH];

void print_help_message();

int main(void) {
    system("clear");
    printf("%s %s\n", PROGRAM_NAME, PROGRAM_VERS);
    printf("Type 'help' for more information. Type 'quit' to exit the program. Type 'cls' to clear the screen\n");

    while (1) {
        printf(">> ");
        fgets(input, INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        // commands
        if (strcmp(input, "quit") == 0) {
            printf("Exiting %s...\n", PROGRAM_NAME);
            return 0;
        } else if (strcmp(input, "help") == 0) {
            print_help_message();
        } else if (strcmp(input, "cls") == 0) {
            system("cls");
        } else {
            if (is_valid_infix_expression(input, error_message, sizeof(error_message))) {
                int evaluation = evaluate_infix_expression(input);
                printf("%d\n", evaluation);
            } else {
                error_print(error_message, 0);
            }
        }
    }

    return 0;
}

void print_help_message() {
    printf("Welcome to %s!\n", PROGRAM_NAME);
}
