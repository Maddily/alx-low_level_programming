#include "lists.h"

/**
 * list_len - Returns the number of nodes in a linked list
 * @h: A pointer to a list_t list
 * Return: The number of nodes in a linked list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		n++;
		current = current->next;
	}
	
	return (n);
}
