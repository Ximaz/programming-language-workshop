/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** compiler.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "program.h"

static op_t *compile_token(const token_t *token)
{
    op_t *op = token_to_op(token);

    if (NULL == op)
        return NULL;
    if (token->type == TOKEN_STR) {
        op->value.v_str = token->value.v_str;
        op->is_value_allocated = 1;
    } else if (token->type == TOKEN_INT) {
        op->value.v_int = token->value.v_int;
        op->is_value_allocated = 0;
    }
    return op;
}

ops_t *ops_compiler(tokens_t *tokens)
{
    uint64_t i = 0;
    ops_t *ops = malloc(sizeof(ops_t));

    if (NULL == ops)
        return NULL;
    ops->count = tokens->_idx;
    ops->ops = malloc(sizeof(op_t *) * ops->count);
    if (NULL == ops->ops) {
        free(ops);
        return NULL;
    }
    for (; tokens->_idx > i; ++i)
        ops->ops[i] = compile_token(tokens->_tokens[i]);
    return ops;
}
