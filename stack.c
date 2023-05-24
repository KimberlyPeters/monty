#include "monty.h"

/**
 * f_stack - Sets the stack mode to stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 * Return: No return value.
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifo = 0;
}
