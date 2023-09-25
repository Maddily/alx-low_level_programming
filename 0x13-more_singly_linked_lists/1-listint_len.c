#include "lists.h"

/**
 * listint_len - Returns the number of nodes in a list.
 * @h: A pointer to the first node in the list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
