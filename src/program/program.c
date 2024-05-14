/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** program.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include "stack.h"

static const op_consumer_t OPS_CONSUMERS[COUNT_OPS] = {
    op_push,
    op_push,
    op_pop,
    op_add,
    op_sub,
    op_dump,
    op_dup,
    op_2dup,
    op_eq,
    op_ne,
    op_gt,
    op_lt,
    op_goet,
    op_loet,
    op_if,
    op_else,
    op_while,
    op_do,
    op_end,
    op_mem,
    op_store,
    op_load,
    op_syscall,
    op_syscall,
    op_syscall,
    op_syscall,
    op_syscall,
    op_syscall,
    op_syscall,
    op_shl,
    op_shr,
    op_orb,
    op_andb,
    op_swap,
    op_over,
};

void debug_memory(char *memory, uint64_t range)
{
    uint64_t i = 0;

    for (; range > i; ++i)
        printf("%02x%c", memory[i],((0 < i) && (0 == i % 8)) ? '\n' : ' ');
    printf("\n\n");
}

int program_execute(ops_t *self)
{
    program_state_t state = { 0 };
    istack_t *stack = stack_new();

    if (NULL == stack)
        return 1;
    state._pc = 0;
    state._op = NULL;
    state._stack = stack;
    state._memory_ptr = 0;
    self = ops_preprocessor(self);
    for (; state._pc < self->count;) {
        state._op = self->ops[state._pc];
        if (0 != OPS_CONSUMERS[state._op->type](&state))
            break;
        if (OP_IF != state._op->type && OP_ELSE != state._op->type &&
            OP_DO != state._op->type && OP_END != state._op->type)
            ++state._pc;
    }
    stack_destroy(stack, NULL);
    ops_destroy(self);
    return (int) state._exit_status;
}
