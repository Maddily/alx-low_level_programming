#include "lists.h"

/**
 * get_dnodeint_at_index - Finds the nth node in a list
 *
 * @head: A pointer to the first node in the list
 * @index: The position of the node to be located
 *
 * Return: A pointer to the node to be found
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	/*If the list is empty*/
	if (head == NULL)
		return (NULL);

	current = head;
	while (current != NULL)
	{
		if (i == index)
			return (current);
		current = current->next;
		i++;
	}

	return (NULL);
}
