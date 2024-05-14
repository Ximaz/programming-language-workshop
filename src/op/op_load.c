/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_load.c
*/

#include <stddef.h>
#include <stdarg.h>
#include "stack.h"
#include "program.h"

int op_load(istack_t *stack, ...)
{
    va_list ap = { 0 };
    char *memory = NULL;
    uint64_t addr = (uint64_t) stack_pop(stack);
    uint64_t byte = 0;

    va_start(ap, stack);
    memory = va_arg(ap, char *);
    va_end(ap);
    byte = memory[addr];
    stack_push(stack, (void *) byte);
    return 0;
}
