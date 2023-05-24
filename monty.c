#include "monty.h"

arg_holder_t arg_holder = {NULL, 1, NULL, NULL};

int main(int argc, char **argv)
{
	arg_holder.arg = NULL;
	arg_holder.SQ = 1;
	arg_holder.input_str = NULL;
	arg_holder.file = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	runByteCode(argv[1]);

	return EXIT_SUCCESS;
}

void runByteCode(char *filename)
{
	char line[MAX_LINE_LENGTH];
	char *command = NULL;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
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
