/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_over.c
*/

#include "program.h"

int op_over(program_state_t *program_state)
{
    void *a = stack_pop(program_state->_stack);
    void *b = stack_pop(program_state->_stack);

    stack_push(program_state->_stack, b);
    stack_push(program_state->_stack, a);
    stack_push(program_state->_stack, b);
    return 0;
}
