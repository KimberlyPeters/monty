#include "monty.h"

/**
 * execute - Executes the Monty opcode.
 * @content: Line content.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number.
 * @file: Pointer to Monty file.
 * Return: Returns 0 on success.
 */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
