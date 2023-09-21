#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * val_s - struct to file pointer
 * @file: file pointer
 * Description: structure file pointer
 */
typedef struct val_s
{
FILE *file;
} val_t;
extern val_t sx;


void _stackfree(stack_t **stack);

int opcode_index(char *opcode, instruction_t my_opcode[]);

void fun_push(stack_t **stack, unsigned int line_number);
void fun_pall(stack_t **stack,
unsigned int line_number __attribute__((unused)));
void fun_pint(stack_t **stack, unsigned int line_number);
void fun_pop(stack_t **stack, unsigned int line_number);
void fun_swap(stack_t **stack, unsigned int line_number);
void fun_add(stack_t **stack, unsigned int line_number);
void fun_nop(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)));
void fun_sub(stack_t **stack, unsigned int line_number);


void _error_inst(int count, char *line_copy);
void _error_file(const char *file);
void _error_argc(void);

#endif
