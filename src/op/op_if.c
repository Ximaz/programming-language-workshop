/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_if.c
*/

#include "program.h"

int op_if(program_state_t *program_state)
{
    int jmp = (0 == (cuint64_t) stack_pop(program_state->_stack));

    if (jmp)
        program_state->_pc = program_state->_op->jmp - 1;
    return 0;
}
