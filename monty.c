#include "monty.h"

/**
 * main - Main program running byte code.
 * @argc: Number of arguments.
 * @argv: Argument in matrix.
 * Return: Return exit success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	runByteCode(argv[1]);
	return (EXIT_SUCCESS);
}

/**
 * runByteCode - Runs the Monty byte code from a file.
 * @filename: Name of the file containing Monty byte code.
 */
void runByteCode(char *filename)
{
	size_t buffer_size = 0;
	FILE *file = NULL;
	char *line = NULL;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char *command = NULL;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &buffer_size, file) != -1)
	{
		if (*line == '\n')
		{
			line_number++;
			continue;
		}
		command = strtok(line, "\n\t ");
		if (command == NULL)
		{
			line_number++;
			continue;
		}
		arg_holder.arg = strtok(NULL, "\n\t ");
		opcode(command, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	fclose(file);
}

/**
 * opcode - Check for operation code.
 * @command: Command input.
 * @line_number: Line number.
 * @stack: Stack of memory.
 */
void opcode(char *command, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (command[0] == '#')
	{
		return;
	}
	if (strcmp(command, "stack") == 0)
	{
		arg_holder.SQ = 1;
		return;
	}
	if (strcmp(command, "queue") == 0)
	{
		arg_holder.SQ = 0;
		return;
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, command) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Free the stack and the input string.
 * @head: Input list pointer.
 */
void free_stack(stack_t **head)
{
	stack_t *current;

	if (head == NULL)
		return;
	free(arg_holder.input_str);
	fclose(arg_holder.file);

	while (*head != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
}
