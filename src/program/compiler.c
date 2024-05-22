/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** compiler.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "program.h"

static const preprocessor_bindings_t PREPROCESSORS[] = {
    { OP_IF, ops_preprocess_if },
    { OP_ELSE, ops_preprocess_else },
    { OP_WHILE, ops_preprocess_while },
    { OP_DO, ops_preprocess_do },
    { OP_END, ops_preprocess_end },
    { COUNT_OPS, NULL }
};

static ops_t *ops_preprocessor(ops_t *self)
{
    pc_t pc = 0;
    op_t *op = NULL;
    cuint64_t i = 0;
    istack_t *stack = stack_new();

    if (NULL == stack)
        return self;
    for (; self->count > pc; ++pc) {
        op = self->ops[pc];
        for (i = 0; NULL != PREPROCESSORS[i].preprocessor &&
            op->type != PREPROCESSORS[i].op; ++i)
            ;
        if (NULL != PREPROCESSORS[i].preprocessor)
            PREPROCESSORS[i].preprocessor(self, op, stack, pc);
    }
    stack_destroy(stack, NULL);
    return self;
}

ops_t *ops_compiler(tokens_t *tokens)
{
    cuint64_t i = 0;
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
        ops->ops[i] = token_to_op(tokens->_tokens[i]);
    return ops_preprocessor(ops);
}
