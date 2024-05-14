/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_syscall.c
*/

#include <unistd.h>
#include "program.h"

/**
 * @brief May have collision when fetching buffers to print, depending on where
 * string are stored. Possible issue with op_mem implementation.
 */
int op_syscall(program_state_t *program_state)
{
    uint64_t i = 0;
    int64_t regs[6] = { 0 };
    uint64_t nparams = program_state->_op->type - OP_SYSCALL0;

    for (; i <= nparams; ++i)
        regs[i] = (uint64_t) stack_pop(program_state->_stack);
    if (2 == nparams && 60 == regs[0]) {
        program_state->_exit_status = regs[1];
        return 256;
    }
    if (3 == nparams && 1 == regs[0])
        write(regs[1], &program_state->_memory[regs[2]], regs[3]);
    return 0;
}
