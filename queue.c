#include "monty.h"

/**
 * queue - Sets the stack mode to queue.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 * Return: No return value.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifo = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack.
 * @n: New value.
 * @stack: Pointer to the stack.
 * Return: No return value.
 */
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *tail;

	tail = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tail)
	{
		while (tail->next)
			tail = tail->next;
	}
	if (!tail)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
	}
}
