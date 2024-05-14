/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** token.h
*/

#ifndef __TOKEN_H_
    #define __TOKEN_H_
    #include "types.h"

typedef struct s_token_location {
    uint64_t row;
    uint64_t col;
} token_location_t;

typedef enum e_token_type {
    TOKEN_IDENTIFIER,
    TOKEN_INT,
    TOKEN_STR,
    TOKEN_TYPES /* Only to know the number of types available. */
} token_type_t;

typedef union u_token_value {
    int64_t v_int;
    char *v_str;
} token_value_t;

typedef struct s_token {
    token_location_t location;
    token_type_t type;
    token_value_t value;
} token_t;

typedef struct s_tokens {
    uint64_t _count;
    uint64_t _idx;
    const char *_filename;
    token_t **_tokens;
} tokens_t;

token_t *token_new(token_location_t location, token_type_t type,
    token_value_t value);

void token_destroy(token_t *self);

tokens_t *tokens_new(uint64_t count, const char *filename);

int tokens_push(tokens_t *self, token_t *token);

token_t *tokens_get(tokens_t *self, uint64_t idx);

void tokens_destroy(tokens_t *self);

#endif /* !__TOKEN_H_ */
