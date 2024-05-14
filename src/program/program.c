/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** program.c
*/

#include <stdlib.h>
#include "program.h"
#include "stack.h"

/*
** self = ops_preprocessor(ops_compile(tokens))
*/
int program_execute(ops_t *self)
{
    pc_t pc = 0;
    op_t *op = NULL;
    char string[STRING_CAPACITY] = { 0 };
    char memory[MEMORY_CAPACITY] = { 0 };
    istack_t *stack = stack_new();

    if (NULL == stack)
        return 1;
    (void)(memory);
    (void)(string);
    (void)(op);
    for (; pc < self->count; ++pc) {
        op = self->ops[pc];
    }
    stack_destroy(stack, NULL);
    return 0;
}
