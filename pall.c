#include "monty.h"
/**
 * f_pall - prints stack
 * @head: head
 * @counter: not used
 * Return: nill
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *i;
	(void)counter;

	i = *head;
	if (i == NULL)
		return;
	for (; i != NULL; i = i->next)
	{
		printf("%d\n", i->n);
	}
}
