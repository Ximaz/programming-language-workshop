/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"

static const char *OPS[COUNT_OPS] = {
    "pop",
    "+",
    "-",
    "dump",
    "dup",
    "2dup",
    "=",
    "!=",
    ">",
    "<",
    ">=",
    "<=",
    "if",
    "else",
    "while",
    "do",
    "end",
    "mem",
    "store",
    "load",
    "syscall0",
    "syscall1",
    "syscall2",
    "syscall3",
    "syscall4",
    "syscall5",
    "syscall6",
    "shl",
    "shr",
    "orb",
    "andb",
    "swap",
    "over",
};

static op_type_t find_op_type(const char *identifier)
{
    op_type_t i = 0;

    for (; COUNT_OPS > i; ++i)
        if (0 == strcmp(OPS[i], identifier))
            return i;
    return COUNT_OPS;
}

static void op_error(const token_t *token)
{
    fprintf(stderr, "Invalid token: %ld:%ld: \"%s\"\n", token->location.row,
        token->location.col, token->value.v_str);
}

static void op_init(op_t *self, const token_t *token)
{
    if (TOKEN_INT == token->type)
        self->type = OP_PUSH_INT;
    if (TOKEN_STR == token->type)
        self->type = OP_PUSH_STR;
    self->is_value_allocated =
        (TOKEN_STR == token->type) || (TOKEN_IDENTIFIER == token->type);
    self->value = token->value;
    self->location = token->location;
    self->jmp = -1;
    self->addr = -1;
}

op_t *token_to_op(const token_t *token)
{
    op_t *op = malloc(sizeof(op_t));

    if (NULL == op)
        return NULL;
    if (TOKEN_IDENTIFIER == token->type) {
        op->type = find_op_type(token->value.v_str);
        if (COUNT_OPS == op->type) {
            free(op);
            op_error(token);
            return NULL;
        }
    }
    op_init(op, token);
    return op;
}

void ops_destroy(ops_t *self)
{
    uint64_t i = 0;

    if (NULL != self && NULL != self->ops) {
        for (; i < self->count; ++i)
            free(self->ops[i]);
        free(self->ops);
    }
    free(self);
}
