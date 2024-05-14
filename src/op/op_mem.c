/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_mem.c
*/

#include "stack.h"
#include "program.h"

int op_mem(program_state_t *program_state)
{
    stack_push(program_state->_stack, (void *) 0);
    return 0;
}
