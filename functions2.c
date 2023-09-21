#include "monty.h"
/**
 * fun_add - .
 * @line_number: .
 * @stack: .
 * Return: .
 */
void fun_add(stack_t **stack, unsigned int line_number)
{
int x, z, sum;
stack_t *temp;
if (*stack == NULL || (*stack)->next == NULL)
{

_stackfree(stack);
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
else
{
temp = *stack;
x = (*stack)->n;
z = (*stack)->next->n;
sum = x + z; 
(*stack)->next->n = sum;

(*stack)->next->prev = NULL;
*stack = (*stack)->next;
free(temp);
}
}

#include "monty.h"
/**
 * fun_nop - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void fun_nop(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
}

#include "monty.h"
/**
 * fun_push - it's function
 * @stack: ...
 * @line_number: .....
 * Return: ......
 */

void fun_push(stack_t **stack, unsigned int line_number)
{
stack_t *new;
char *ch;
int data;

ch = strtok(NULL, " ,\n");
if (ch == NULL)
{
_stackfree(stack);
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(sx.file);
exit(EXIT_FAILURE);
}

new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(sx.file);
exit(EXIT_FAILURE);
}

data = atoi(ch);

new->n = data;
new->prev = NULL;

if (*stack == NULL)
{
new->next = NULL;
*stack = new;
}
else
{
new->next = *stack;
(*stack)->prev = new;
*stack = new;
}
}
