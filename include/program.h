/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** program.h
*/

#ifndef __PROGRAM_H_
    #define __PROGRAM_H_
    #include "stack.h"
    #include "op.h"
    #define STRING_CAPACITY 64000 /* 64kb */
    #define STACK_CAPACITY 64000  /* 64kb */
    #define MEMORY_CAPACITY (STRING_CAPACITY + STACK_CAPACITY)

typedef void (*preprocessor_t)(ops_t *ops, op_t *op, istack_t *stack, pc_t pc);

typedef struct s_preprocessor_bindings {
    op_type_t op;
    preprocessor_t preprocessor;
} preprocessor_bindings_t;

ops_t *ops_preprocessor(ops_t *self);

void ops_destroy(ops_t *self);

ops_t *ops_compiler(tokens_t *tokens);

#endif /* !__PROGRAM_H_ */
