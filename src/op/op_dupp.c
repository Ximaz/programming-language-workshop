/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_dup.c
*/

#include "program.h"

int op_dup(program_state_t *program_state)
{
    void *data = stack_pop(program_state->_stack);

    stack_push(program_state->_stack, data);
    stack_push(program_state->_stack, data);
    return 0;
}
