/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "string_utils.h"

static int usage(const char *program)
{
    printf("Usage: %s <source>\n", program);
    return 84;
}

static int file_error(const char *source)
{
    printf("Unable to open the source file '%s'\n", source);
    return 84;
}

int main(int argc, const char *argv[])
{
    int status = 0;
    char *source = NULL;
    tokens_t *tokens = NULL;

    if (2 != argc)
        return usage(*argv);
    source = read_file(argv[1]);
    if (NULL == source)
        return file_error(argv[1]);
    tokens = lex_source(*argv, source);
    free(source);
    tokens_debug(tokens);
    tokens_destroy(tokens);
    return status;
}
