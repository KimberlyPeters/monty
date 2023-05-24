#include "monty.h"

/**
 * pall - Prints the elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	(void)line_number;

	current_node = *stack;
	if (current_node == NULL)
		return;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
