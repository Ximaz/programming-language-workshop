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

static const op_binding_t OPS[] = {
    { "pop", OP_POP },
    { "+", OP_ADD },
    { "-", OP_SUB },
    { "dump", OP_DUMP },
    { "dup", OP_DUP },
    { "2dup", OP_2DUP },
    { "=", OP_EQUAL },
    { "!=", OP_DIFF },
    { ">", OP_GT },
    { "<", OP_LT },
    { ">=", OP_GOET },
    { "<=", OP_LOET },
    { "if", OP_IF },
    { "else", OP_ELSE },
    { "while", OP_WHILE },
    { "do", OP_DO },
    { "end", OP_END },
    { "mem", OP_MEM },
    { "store", OP_STORE },
    { "load", OP_LOAD },
    { "syscall0", OP_SYSCALL0 },
    { "syscall1", OP_SYSCALL1 },
    { "syscall2", OP_SYSCALL2 },
    { "syscall3", OP_SYSCALL3 },
    { "syscall4", OP_SYSCALL4 },
    { "syscall5", OP_SYSCALL5 },
    { "syscall6", OP_SYSCALL6 },
    { "shl", OP_SHL },
    { "shr", OP_SHR },
    { "orb", OP_ORB },
    { "andb", OP_ANDB },
    { "swap", OP_SWAP },
    { "over", OP_OVER },
    { NULL, -1 }
};

static op_type_t find_op_type(const char *identifier)
{
    op_type_t i = 0;

    for (; NULL != OPS[i].identifier; ++i)
        if (0 == strcmp(OPS[i].identifier, identifier))
            return OPS[i].op;
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
    cuint64_t i = 0;

    if (NULL != self && NULL != self->ops) {
        for (; self->count > i; ++i)
            free(self->ops[i]);
        free(self->ops);
    }
    free(self);
}
