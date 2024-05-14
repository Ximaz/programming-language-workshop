/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_dump.c
*/

#include <stdio.h>
#include "program.h"

int op_dump(program_state_t *program_state)
{
    printf("%ld\n", (cint64_t) stack_pop(program_state->_stack));
    return 0;
}
