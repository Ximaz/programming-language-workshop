/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** lexer.h
*/

#ifndef __LEXER_H_
    #define __LEXER_H_
    #include "types.h"
    #include "token.h"
    #define COMMENT "//"
    #define COMMENT_LEN 2

cuint64_t run_until_predicate(const char *source, cuint64_t start,
    char predicate);

cuint64_t run_while_predicate(const char *source, cuint64_t start,
    char predicate);

tokens_t *lex_source(const char *filename, const char *source);

token_t *lexem_string(const char *line, token_location_t *location);

token_t *lexem_identifier(const char *line, token_location_t *location);

void lexer_error(const tokens_t *tokens, const token_location_t *location,
    const char *error);

#endif /* !__LEXER_H_ */
