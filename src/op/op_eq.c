/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_eq.c
*/

#include "program.h"

int op_eq(program_state_t *program_state)
{
    cuint64_t a = (cuint64_t) stack_pop(program_state->_stack);
    cuint64_t b = (cuint64_t) stack_pop(program_state->_stack);

    stack_push(program_state->_stack, (void *) (cuint64_t) (a == b));
    return 0;
}
