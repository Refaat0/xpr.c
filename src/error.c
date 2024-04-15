#include "../include/error.h"
#include <stdio.h>

void error_print(char *error_message, int columns) {
    fprintf(stderr, "%s%s%s\n", COLOUR_RED, error_message, COLOUR_RESET);
}
