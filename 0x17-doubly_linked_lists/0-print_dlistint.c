#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a list
 *
 * @h: A pointer to the first node in the list
 *
 * Return: The number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *c;
	size_t n = 0;

	if (h == NULL)
		return (0);

	c = h;

	while (c != NULL)
	{
		printf("%d\n", c->n);
		n++;
		c = c->next;
	}

	return (n);
}
