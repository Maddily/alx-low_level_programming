#include "lists.h"

/**
 * dlistint_len - Finds the number of elements in a linked list
 *
 * @h: A pointer to the first node in the list
 *
 * Return: The number of elements in the list
*/
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *c;
	int n = 0;

	/*If the list is empty*/
	if (h == NULL)
		return (0);

	c = h;

	while (c != NULL)
	{
		n++;
		c = c->next;
	}

	return (n);
}
