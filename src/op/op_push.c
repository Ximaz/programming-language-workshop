/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_push.c
*/

#include <stdio.h>
#include <string.h>
#include "program.h"

static void op_push_string(program_state_t *program_state,
    cuint64_t string_length)
{
    cuint64_t addr = 0;

    stack_push(program_state->_stack, (void *) string_length);
    addr = STRING_CAPACITY + program_state->_memory_ptr;
    stack_push(program_state->_stack, (void *) addr);
    strncpy(&(program_state->_memory[addr]),
        program_state->_op->value.v_str, string_length);
    program_state->_memory_ptr += string_length;
}

int op_push(program_state_t *program_state)
{
    cuint64_t string_length = 0;

    if (OP_PUSH_INT == program_state->_op->type) {
        stack_push(program_state->_stack,
            (void *) (cuint64_t) program_state->_op->value.v_int);
        return 0;
    }
    string_length = strlen(program_state->_op->value.v_str);
    if (STRING_CAPACITY < (program_state->_memory_ptr + string_length)) {
        fprintf(stderr, "String buffer overflow: '%s' not copied.\n",
            program_state->_op->value.v_str);
        program_state->_exit_status = -1;
        return -1;
    }
    op_push_string(program_state, string_length);
    return 0;
}
