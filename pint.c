#include "monty.h"

/**
 * pint - Print the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
