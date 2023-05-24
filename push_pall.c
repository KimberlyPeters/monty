#include "monty.h"

/**
 * pall - print out all the elements of the stack
 * @stack: the stack
 * @line_num: line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void)line_num;
	if (*stack == NULL)
		return;

	for (current = *stack; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
	}
}
i
/**
 * push - push integers to the stack or queue
 * @stack: pointer to the stack
 * @line_num: line number
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	if (!isnum(arg_holder.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{

