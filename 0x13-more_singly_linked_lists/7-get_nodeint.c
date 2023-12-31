#include "lists.h"

/**
 * get_nodeint_at_index - Finds a node at a given index.
 * @head: A pointer to the first node.
 * @index: The node's index.
 *
 * Return: A pointer to the node at the given index.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;

	if (head == NULL)
		return (NULL);

	if (index == 0)
		return (head);

	current = head;
	while (index > 1 && current != NULL)
	{
		current = current->next;
		index--;
	}

	if (index > 1 || current == NULL)
		return (NULL);

	return (current->next);
}
