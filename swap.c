#include "monty.h"

/**
 * f_swap - adds top two elements of stack.
 * @head: head
 * @counter: line_number
 * Return: NO
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *i;
	int len = 0, auxil;
	
	for (i = *head; i != NULL; i = i->next)
	{
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = *head;
	auxil = i->n;
	i->n = i->next->n;
	i->next->n = auxil;
}
