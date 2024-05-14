/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_lt.c
*/

#include "program.h"

int op_lt(program_state_t *program_state)
{
    cint64_t a = (cint64_t) stack_pop(program_state->_stack);
    cint64_t b = (cint64_t) stack_pop(program_state->_stack);

    stack_push(program_state->_stack, (void *) (cuint64_t) (b < a));
    return 0;
}
