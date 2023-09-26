#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - Prints a list.
 * @head: A pointer to the first node in the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *t, *h;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	t = h = head;

	while (t != NULL)
	{
		printf("[%p] %d\n", (void *)t, t->n);
		t = t->next;
		count++;
		if (h != NULL && h->next != NULL)
		{
			h = h->next->next;
			if (t == h)
			{
				printf("[%p] %d\n", (void *)t, t->n);
				printf("[%p] %d\n", (void *)(t->next), t->next->n);
				printf("-> [%p] %d\n", (void *)(t->next->next), t->next->next->n);
				exit(98);
			}
		}
	}

	return (count);
}
