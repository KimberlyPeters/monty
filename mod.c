#include "monty.h"
/**
 * f_mod - a function that computes the rest of the division of the
 * second top element of the stack by the top element of the stack
 * @head: head of stack
 * @counter: line_number
 * Return: no
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *i;
	int len = 0, auxil;

	for (i = *head; i != NULL; i->next)
		len++;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = *head;
	if (i->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxil = i->next->n % i->n;
	i->next->n = auxil;
	*head = i->next;
	free(i);
}
