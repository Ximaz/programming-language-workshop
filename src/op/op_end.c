/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_end.c
*/

#include "program.h"

int op_end(program_state_t *program_state)
{
    program_state->_pc = program_state->_op->jmp;
    return 0;
}
