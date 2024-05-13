/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** tokens.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

tokens_t *tokens_new(uint64_t count, const char *filename)
{
    tokens_t *self = malloc(sizeof(tokens_t));

    if (NULL != self) {
        self->_count = count;
        self->_idx = 0;
        self->_filename = filename;
        self->_tokens = calloc(count, sizeof(token_t *));
    }
    return self;
}

int tokens_push(tokens_t *self, token_t *token)
{
    if (self->_count == self->_idx)
        return -1;
    self->_tokens[self->_idx] = token;
    ++self->_idx;
    return 0;
}

token_t *tokens_get(tokens_t *self, uint64_t idx)
{
    if (self->_count <= idx)
        return NULL;
    return self->_tokens[idx];
}

void tokens_destroy(tokens_t *self)
{
    uint64_t i = 0;

    if (NULL != self && NULL != self->_tokens) {
        for (; i < self->_count; ++i)
            token_destroy(self->_tokens[i]);
        free(self->_tokens);
    }
    free(self);
}

void tokens_debug(const tokens_t *self)
{
    uint64_t i = 0;
    token_t *token = NULL;

    printf("Tokens for the file %s :\n", self->_filename);
    for (; NULL != self->_tokens[i]; ++i) {
        token = self->_tokens[i];
        if (TOKEN_STR == token->type)
            printf("TokenType: TOKEN_STR | Loc: %llu:%llu | Value: %s\n",
                token->location.row, token->location.col, token->value.v_str);
        if (TOKEN_IDENTIFIER == token->type)
            printf("TokenType: TOKEN_IDENTIFIER | Loc: %llu:%llu | Value: %s\n",
                token->location.row, token->location.col, token->value.v_str);
        if (TOKEN_INT == token->type)
            printf("TokenType: TOKEN_IDENTIFIER | Loc: %llu:%llu | Value: %lld\n",
                token->location.row, token->location.col, token->value.v_int);
    }
    printf("Tokens count: %llu\n", i);
}
