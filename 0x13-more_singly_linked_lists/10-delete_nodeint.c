#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A pointer to the pointer pointing to the first node in a list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *tmp;

	if (index == 0)
	{
		if (*head == NULL)
			return (-1);
		current = (*head)->next;
		free(*head);
		*head = current;
		return (1);
	}
	if (*head == NULL)
		return (-1);

	current = *head;
	while (index > 1 && current != NULL)
	{
		current = current->next;
		index--;
	}
	if (index > 1 || current->next == NULL)
		return (-1);

	tmp = current->next->next;
	free(current->next);
	current->next = tmp;
	return (1);
}
