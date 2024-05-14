/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op.h
*/

#ifndef __OP_H_
    #define __OP_H_
    #include "token.h"
    #include "types.h"
    #include "stack.h"

typedef enum e_op_type {
    OP_PUSH_INT,
    OP_PUSH_STR,
    OP_POP,
    OP_ADD,
    OP_SUB,
    OP_DUMP,
    OP_DUP,
    OP_2DUP,
    OP_EQUAL,
    OP_DIFF,
    OP_GT,
    OP_LT,
    OP_GOET,
    OP_LOET,
    OP_IF,
    OP_ELSE,
    OP_WHILE,
    OP_DO,
    OP_END,
    OP_MEM,
    OP_STORE,
    OP_LOAD,
    OP_SYSCALL0,
    OP_SYSCALL1,
    OP_SYSCALL2,
    OP_SYSCALL3,
    OP_SYSCALL4,
    OP_SYSCALL5,
    OP_SYSCALL6,
    OP_SHL,
    OP_SHR,
    OP_ORB,
    OP_ANDB,
    OP_SWAP,
    OP_OVER,
    COUNT_OPS
} op_type_t;

typedef struct s_op {
    op_type_t type;
    token_location_t location;

    /**
     * @brief (`OP_PUSH_INT` and `OP_PUSH_STR` ops only) Contains the value to
     * push onto the stack.
     */
    token_value_t value;

    /**
     * @brief Required when it's time to free the op.
     */
    int is_value_allocated;

    /**
     * @brief Exists only for control-flow ops. Contains an index of an op
     * within the program that the execution has to jump to depending on the
     * circumstantces.
     * In case of `if` it's the place of `else` branch.
     * In case of `else` it's the end of the construction.
     * The default value will be -1, which marks it as unset.
     */
    cint64_t jmp;

    /**
     * @brief (`OP_PUSH_STR` op only) Contains the address where the string was
     * pushed in the memory.
     */
    cint64_t addr;
} op_t;

typedef struct s_op_binding {
    const char *identifier;
    op_type_t op;
} op_binding_t;

typedef struct s_ops {
    cuint64_t count;
    op_t **ops;
} ops_t;

op_t *token_to_op(const token_t *token);

#endif /* !__OP_H_ */
