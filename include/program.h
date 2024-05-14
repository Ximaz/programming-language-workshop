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

typedef struct s_program_state {
    pc_t _pc;
    op_t *_op;
    istack_t *_stack;
    char _memory[MEMORY_CAPACITY];
    uint64_t _memory_ptr;
    int64_t _exit_status;
} program_state_t;

typedef int (*op_consumer_t)(program_state_t *program_state);

int op_push(program_state_t *program_state);
int op_pop(program_state_t *program_state);
int op_add(program_state_t *program_state);
int op_sub(program_state_t *program_state);
int op_dump(program_state_t *program_state);
int op_dup(program_state_t *program_state);
int op_2dup(program_state_t *program_state);
int op_eq(program_state_t *program_state);
int op_ne(program_state_t *program_state);
int op_gt(program_state_t *program_state);
int op_lt(program_state_t *program_state);
int op_goet(program_state_t *program_state);
int op_loet(program_state_t *program_state);
int op_if(program_state_t *program_state);
int op_else(program_state_t *program_state);
int op_while(program_state_t *program_state);
int op_do(program_state_t *program_state);
int op_end(program_state_t *program_state);
int op_mem(program_state_t *program_state);
int op_store(program_state_t *program_state);
int op_load(program_state_t *program_state);
int op_syscall(program_state_t *program_state);
int op_shl(program_state_t *program_state);
int op_shr(program_state_t *program_state);
int op_orb(program_state_t *program_state);
int op_andb(program_state_t *program_state);
int op_swap(program_state_t *program_state);
int op_over(program_state_t *program_state);

int program_execute(ops_t *self);

#endif /* !__PROGRAM_H_ */
