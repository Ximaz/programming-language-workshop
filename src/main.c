/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "program.h"
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
    int exit_status = 0;
    ops_t *ops = NULL;
    char *source = NULL;
    tokens_t *tokens = NULL;

    if (2 != argc)
        return usage(*argv);
    source = read_file(argv[1]);
    if (NULL == source)
        return file_error(argv[1]);
    tokens = lex_source(*argv, source);
    free(source);
    ops = ops_compiler(tokens);
    exit_status = program_execute(ops);
    tokens_destroy(tokens);
    return exit_status;
}
