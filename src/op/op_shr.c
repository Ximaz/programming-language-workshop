/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_shr.c
*/

#include "program.h"

int op_shr(program_state_t *program_state)
{
    int64_t a = (int64_t) stack_pop(program_state->_stack);
    int64_t b = (int64_t) stack_pop(program_state->_stack);

    stack_push(program_state->_stack, (void *) (uint64_t) (b >> a));
    return 0;
}