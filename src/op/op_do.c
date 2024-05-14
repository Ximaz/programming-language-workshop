/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_do.c
*/

#include "program.h"

int op_do(program_state_t *program_state)
{
    int jmp = (0 == (uint64_t) stack_pop(program_state->_stack));

    if (jmp)
        program_state->_pc = program_state->_op->jmp;
    else
        ++program_state->_pc;
    return 0;
}
