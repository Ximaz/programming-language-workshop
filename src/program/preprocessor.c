/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** preprocessor.c
*/

#include <assert.h>
#include <stdlib.h>
#include "op.h"
#include "stack.h"
#include "program.h"

static void ops_preprocess_if(ops_t *ops, op_t *op, istack_t *stack, pc_t pc);
static void ops_preprocess_else(ops_t *ops, op_t *op, istack_t *stack,
    pc_t pc);
static void ops_preprocess_while(ops_t *ops, op_t *op, istack_t *stack,
    pc_t pc);
static void ops_preprocess_do(ops_t *ops, op_t *op, istack_t *stack, pc_t pc);
static void ops_preprocess_end(ops_t *ops, op_t *op, istack_t *stack, pc_t pc);

static const preprocessor_bindings_t PREPROCESSORS[] = {
    { OP_IF, ops_preprocess_if },
    { OP_ELSE, ops_preprocess_else },
    { OP_WHILE, ops_preprocess_while },
    { OP_DO, ops_preprocess_do },
    { OP_END, ops_preprocess_end },
    { COUNT_OPS, NULL }
};

/**
 * @brief To preprocess the OP_IF op, we set it's jmp address to itself (AKA
 * the current program counter), and then we will modify it when preprocessing
 * the corresponding OP_ELSE op.
 */
static void ops_preprocess_if(ops_t *ops, op_t *op, istack_t *stack, pc_t pc)
{
    (void)(ops);
    (void)(op);
    stack_push(stack, (void *) pc);
}

/**
 * @brief To preprocess the OP_ELSE op, we first check it's associated OP_IF.
 * From that, we set the OP_IF jump's address to the OP_ELSE + 1, which
 * relatively points to the instruction right after OP_ELSE. Finally, the
 * OP_ELSE points to itself for now, and will be changed by the OP_END's
 * address later on, so that we can escape the OP_ELSE statement in case OP_IF
 * had beed executed.
 */
static void ops_preprocess_else(ops_t *ops, op_t *op, istack_t *stack, pc_t pc)
{
    uint64_t if_addr = (uint64_t) stack_pop(stack);
    op_t *op_if = ops->ops[if_addr];

    (void)(op);
    assert(OP_IF == op_if->type);
    op_if->jmp = pc + 1;
    stack_push(stack, (void *) pc);
}

/**
 * @brief To preprocess the OP_WHILE op, we push it's address onto the stack,
 * so that when preprocessing the OP_DO op, we can retrieve it to build the
 * loop.
 */
static void ops_preprocess_while(ops_t *ops, op_t *op, istack_t *stack,
    pc_t pc)
{
    (void)(ops);
    (void)(op);
    stack_push(stack, (void *) pc);
}

/**
 * @brief To preprocess the OP_DO, we pop the OP_WHILE's address from the stack
 * and we make the OP_DO op pointing to that address, thus creating the loop
 * contorl-flow.
 */
static void ops_preprocess_do(ops_t *ops, op_t *op, istack_t *stack, pc_t pc)
{
    uint64_t while_addr = (uint64_t) stack_pop(stack);
    op_t *op_while = ops->ops[while_addr];

    assert(op_while->type == OP_WHILE);
    op->jmp = while_addr;
    stack_push(stack, (void *) pc);
}

/**
 * @brief To preprocess the OP_END op, we need to handle multiple scenarios :
 *
 * If the op that OP_END is closing is either OP_IF or OP_ELSE :
 * - we change the control flow's jmp address to OP_END's one, so that it
 *   actually closes the control flow.
 * - we set the address of OP_END to the current program counter, to continue
 *   the execution after it.
 *
 * If the op that OP_END is closing is OP_DO :
 * - we change the OP_END jump's address to the OP_DO's one, which already has
 *   been preprocessed to point to the while's address.
 */
static void ops_preprocess_end(ops_t *ops, op_t *op, istack_t *stack, pc_t pc)
{
    uint64_t block_decl_addr = (uint64_t) stack_pop(stack);
    op_t *block_decl_op = ops->ops[block_decl_addr];

    if (OP_IF == block_decl_op->type || OP_ELSE == block_decl_op->type) {
        block_decl_op->jmp = pc;
        op->jmp = pc + 1;
        return;
    }
    if (OP_DO == block_decl_op->type) {
        op->jmp = block_decl_op->jmp;
        block_decl_op->jmp = pc + 1;
        return;
    }
    assert(0);
}

ops_t *ops_preprocessor(ops_t *self)
{
    pc_t pc = 0;
    op_t *op = NULL;
    uint64_t i = 0;
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
