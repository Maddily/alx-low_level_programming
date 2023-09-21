#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all of the elements of a `list_t` list.
 * @h: A pointer to a `list_t` list (struct).
 * Return: The number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		if (current->str == NULL)
		{
			printf("%s\n", "[0] (nil)");
		}
		else
		{
			printf("[%u] %s\n", current->len, current->str);
		}
		n++;
		current = current->next;
	}
	return (n);
}
