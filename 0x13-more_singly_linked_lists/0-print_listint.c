#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all of the nodes in a list.
 * @h: A pointer to the first node in the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}

	return (count);
}
