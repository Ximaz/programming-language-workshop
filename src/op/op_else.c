/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_else.c
*/

#include "program.h"

int op_else(program_state_t *program_state)
{
    program_state->_pc = program_state->_op->jmp;
    return 0;
}
