#include "monty.h"
/**
 * fun_pall - ...
 * @line_number: ...
 * @stack: ...
 * Return: ....
 */
void fun_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{

stack_t *temp;
temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
 * fun_pint - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void fun_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack) == NULL)
{
_stackfree(stack);
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
fclose(sx.file);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * fun_pop - ...
 * @stack: ...
 * @line_number: ....
 * Return: .....
 */
void fun_pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if ((*stack) == NULL)
{

_stackfree(stack);
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
fclose(sx.file);
exit(EXIT_FAILURE);
}

if ((*stack)->next == NULL)
{
free(*stack);
*stack = NULL;
return;
}

temp = *stack;

(*stack)->next->prev = NULL;
*stack = (*stack)->next;
free(temp);
}

/**
 * fun_sub - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void fun_sub(stack_t **stack, unsigned int line_number)
{
int x, z, sub;
stack_t *temp;
if (*stack == NULL || (*stack)->next == NULL)
{

_stackfree(stack);
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
fclose(sx.file);
exit(EXIT_FAILURE);
}
else
{
temp = *stack;
x = (*stack)->n;
z = (*stack)->next->n;
sub = z - x;
(*stack)->next->n = sub;

(*stack)->next->prev = NULL;
*stack = (*stack)->next;
free(temp);
}
}

/**
 * fun_swap - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void fun_swap(stack_t **stack, unsigned int line_number)
{
int x, z, temp;
if (*stack == NULL || (*stack)->next == NULL)
{

_stackfree(stack);
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(sx.file);
exit(EXIT_FAILURE);
}
else
{
x = (*stack)->n;
z = (*stack)->next->n;
temp = z;
z = x;
x = temp;
(*stack)->n = x;
(*stack)->next->n = z;
}
}
