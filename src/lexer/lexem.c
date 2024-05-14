/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** lexem.c
*/

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

token_t *lexem_string(const char *line, token_location_t *location)
{
    token_t *token = NULL;
    token_type_t type = TOKEN_STR;
    token_value_t value;
    uint64_t len = run_until_predicate(line, location->col + 1, '"');
    char *string = calloc(len, sizeof(char));

    if (NULL == string)
        return NULL;
    strncpy(string, &line[location->col + 1], len - location->col - 1);
    value.v_str = string;
    token = token_new(*location, type, value);
    if (NULL == token)
        free(string);
    location->col = run_while_predicate(line, len + 1, ' ');
    return token;
}

static token_t *lexem_integer(int64_t num, token_location_t *location)
{
    token_value_t value;

    if ((num == LONG_MIN || num == LONG_MAX) && ERANGE == errno)
        return NULL;
    value.v_int = num;
    return token_new(*location, TOKEN_INT, value);
}

token_t *lexem_identifier(const char *line, token_location_t *location)
{
    char *endp = NULL;
    token_value_t value;
    token_t *token = NULL;
    uint64_t len = run_until_predicate(line, location->col + 1, ' ');
    char *id = calloc(len + 1, sizeof(char));

    if (NULL == id)
        return NULL;
    strncpy(id, &line[location->col], len - location->col);
    value.v_int = strtol(id, &endp, 10);
    if (0 == *endp) {
        free(id);
        token = lexem_integer(value.v_int, location);
    } else {
        value.v_str = id;
        token = token_new(*location, TOKEN_IDENTIFIER, value);
        if (NULL == token)
            free(id);
    }
    location->col = run_while_predicate(line, len, ' ');
    return token;
}
