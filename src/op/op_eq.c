/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_eq.c
*/

#include "program.h"

int op_eq(program_state_t *program_state)
{
    uint64_t a = (uint64_t) stack_pop(program_state->_stack);
    uint64_t b = (uint64_t) stack_pop(program_state->_stack);

    stack_push(program_state->_stack, (void *) (uint64_t) (a == b));
    return 0;
}
