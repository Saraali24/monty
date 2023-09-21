#include "monty.h"
/**
 * find_opcode - .
 * @opcode: .
 * @my_opcode: ........
 * Return: .
 */

int opcode_index(char *opcode, instruction_t my_opcode[])
{
int i;
for (i = 0; i < 8; i++)
{
if (strcmp(opcode, my_opcode[i].opcode) == 0)
return (i);
}
return (-1);
}

/**
 * free_stack - .
 * @stack: .
 * Return: .
 */
void _stackfree(stack_t **stack)
{

if (*stack)
{
while ((*stack)->next != NULL)
{
*stack = (*stack)->next;
free((*stack)->prev);
}
free(*stack);
}
}
/**
 * _error_argc - .
 * Return: .
 */
void _error_argc(void)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
/**
 * _error_file - .
 * @file: .
 * Return: .
 */
void _error_file(const char *file)
{
fprintf(stderr, "Error: Can't open file %s\n", file);
exit(EXIT_FAILURE);
}
/**
 * _error_inst - .
 * @line_copy: .
 * @count: .
 * Return: .
 */
void _error_inst(int count, char *line_copy)
{
fprintf(stderr, "L%d: unknown instruction %s\n", count, line_copy);
fclose(sx.file);
exit(EXIT_FAILURE);
}
