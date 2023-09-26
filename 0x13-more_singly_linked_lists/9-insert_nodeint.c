#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given index.
 * @head: A pointer to the pointer pointing to the first node in a list.
 * @idx: The index at which to insert the new node.
 * @n: The data to be added to the new node.
 *
 * Return: A pointer to the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current = *head;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL || (idx != 0 && *head == NULL))
		return (NULL);
	new->n = n;
	if (idx == 0 && *head != NULL)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	if (idx == 0)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}
	while (idx > 1 && current != NULL)
	{
		current = current->next;
		idx--;
	}
	if (idx > 1)
	{
		free(new);
		return (NULL);
	}
	else if (current->next == NULL)
	{
		current->next = new;
		new->next = NULL;
	}
	else
	{
		new->next = current->next;
		current->next = new;
	}
	return (new);
}
