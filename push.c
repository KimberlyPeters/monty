#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number.
 * Return: No return value.
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	int num, i = 0, invalid_flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > '9' || bus.arg[i] < '0')
				invalid_flag = 1;
		}
		if (invalid_flag == 1)
		{
			fprintf(stderr, "L%d: usage: f_push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: f_push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.lifo == 0)
		add_node(stack, num);
	else
		add_queue(stack, num);
}
