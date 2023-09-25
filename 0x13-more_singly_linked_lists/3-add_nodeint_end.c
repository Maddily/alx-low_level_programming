#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a list.
 * @head: A pointer to the pointer pointing to the first node in the list.
 * @n: Data to be added to the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current;
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}

	return (new);
}
