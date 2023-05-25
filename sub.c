#include "monty.h"
/**
  * f_sub- subtraction
  * @head: head of stack
  * @counter: line_number
  * Return: no
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *auxil;
	int sub, nodes;

	auxil = *head;
	nodes = 0;

	while (auxil != NULL)
	{
		nodes++;
		auxil = auxil->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxil = *head;
	sub = auxil->next->n - auxil->n;
	auxil->next->n = sub;
	*head = auxil->next;
	free(auxil);
}
