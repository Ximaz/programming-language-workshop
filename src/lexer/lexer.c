/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** lexer.c
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "lexer.h"
#include "string_utils.h"
#include "token.h"

static cuint64_t compute_tokens_count(const char *line)
{
    cuint64_t j = 0;
    cuint64_t i = run_while_predicate(line, 0, ' ');
    cuint64_t count = 0;

    for (; 0 != line[i]; ++i) {
        if ('"' == line[i]) {
            j = run_until_predicate(line, i + 1, '"');
            ++count;
            i = j + 1;
            continue;
        }
        j = run_while_predicate(line, i, ' ');
        count += j > i;
        i = j;
    }
    return count + (0 < i);
}

static cuint64_t get_tokens_count(char **lines)
{
    cuint64_t i = 0;
    cuint64_t count = 0;

    for (; NULL != lines[i]; ++i)
        count += compute_tokens_count(lines[i]);
    return count;
}

static void lex_line(tokens_t *tokens, const char *line, cuint64_t row)
{
    token_t *token = NULL;
    token_location_t location = { 0, 0 };
    cuint64_t col = run_while_predicate(line, 0, ' ');

    location.row = row;
    while (0 != strncmp(&line[col], COMMENT, COMMENT_LEN) && 0 != line[col]) {
        location.col = col;
        if ('"' == line[col])
            token = lexem_string(line, &location);
        else
            token = lexem_identifier(line, &location);
        if (NULL == token) {
            lexer_error(tokens, &location, "Unknowned token");
            break;
        }
        tokens_push(tokens, token);
        col = location.col;
    }
}

cuint64_t run_until_predicate(const char *source, cuint64_t start,
    char predicate)
{
    while (0 != source[start] && predicate != source[start])
        ++start;
    return start;
}

cuint64_t run_while_predicate(const char *source, cuint64_t start,
    char predicate)
{
    while (predicate == source[start])
        ++start;
    return start;
}

void lexer_error(const tokens_t *tokens, const token_location_t *location,
    const char *error)
{
    fprintf(stderr, "%s:%lu:%lu: %s\n", tokens->_filename, location->row,
        location->col, error);
}

tokens_t *lex_source(const char *filename, const char *source)
{
    cuint64_t i = 0;
    tokens_t *tokens = NULL;
    cuint64_t count = 0;
    char **lines = split(source, "\n");

    if (NULL == lines)
        return NULL;
    count = get_tokens_count(lines);
    tokens = tokens_new(count, filename);
    if (NULL == tokens) {
        destroy_split(lines);
        return NULL;
    }
    for (; NULL != lines[i]; ++i)
        lex_line(tokens, lines[i], i + 1);
    destroy_split(lines);
    return tokens;
}
