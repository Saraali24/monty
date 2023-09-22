#include "monty.h"
/**
 * main - monty program
 * @argc: num of arguments
 * @argv: argument vectors
 * Return: 0
 */
int main(int argc, char **argv)
{
char line[100], *copy_ptr, *command;
int i, check;
unsigned int count = 0;
instruction_t my_opcode[] = {{"push", fun_push},
{"pall", fun_pall},
{"pint", fun_pint},
{"pop", fun_pop},
{"swap", fun_swap},
{"add", fun_add},
{"nop", fun_nop},
{"sub", fun_sub}};
stack_t *stack;
stack = NULL;
if (argc != 2)
_error_argc();
sx.file = fopen(argv[1], "r");
if (sx.file == NULL)
_error_file(argv[1]);
while (fgets(line, sizeof(line), sx.file) != NULL)
{
count++;
copy_ptr = strcat(line, "\0");
command = strtok(copy_ptr, " ,\n");
if (command == NULL || command[0] == '#')
continue;
i = opcode_index(command, my_opcode);
if (i >= 0)
my_opcode[i].f(&stack, count);
else
_error_inst(count, copy_ptr);
}
check = fclose(sx.file);
if (check == -1)
exit(-1);
_stackfree(&stack);
return (0);
}
