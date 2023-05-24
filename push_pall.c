#include "monty.h"

/**
 * is_number - check if string is a number
 * @str: string input
 * Return: 0 if false, 1 if true
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * push_stack - LIFO data type
 * @stack: stack of the memory
 * @new_node: new stack node to add
 */
void push_stack(stack_t **stack, stack_t *new_node)
{
	new_node->n = atoi(arg_holder.arg);
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * push_queue - FIFO data type
 * @stack: stack of the memory
 * @new_node: new stack node to add
 */
void push_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *holder;

	new_node->n = atoi(arg_holder.arg);
	new_node->next = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		holder = *stack;
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new_node;
		new_node->prev = holder;
	}
}

/**
 * push - push integers to memory
 * @stack: stack of memory
 * @line_num: line number
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (!(is_number(arg_holder.arg)))
	{
		printf("L%u: usage: push integer\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (arg_holder.SQ)
		push_stack(stack, new_node);
	else
		push_queue(stack, new_node);
}

/**
 * pall - print out all the stack
 * @stack: the stack
 * @line_num: line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void)line_num;
	if (*stack == NULL)
		return;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
