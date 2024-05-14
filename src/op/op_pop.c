/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_pop.c
*/

#include "program.h"

int op_pop(program_state_t *program_state)
{
    stack_pop(program_state->_stack);
    return 0;
}
