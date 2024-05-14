/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_store.c
*/

#include "program.h"

int op_store(program_state_t *program_state)
{
    cuint64_t byte = (cuint64_t) stack_pop(program_state->_stack);
    cuint64_t addr = (cuint64_t) stack_pop(program_state->_stack);

    program_state->_memory[addr] = byte % 0xff;
    return 0;
}
