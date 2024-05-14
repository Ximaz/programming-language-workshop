/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_load.c
*/

#include <stdio.h>
#include <stddef.h>
#include "program.h"

int op_load(program_state_t *program_state)
{
    uint64_t addr = (uint64_t) stack_pop(program_state->_stack);
    uint64_t byte = program_state->_memory[addr];

    stack_push(program_state->_stack, (void *) byte);
    return 0;
}
