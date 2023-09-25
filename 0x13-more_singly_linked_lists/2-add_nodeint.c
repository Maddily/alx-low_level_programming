#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a list.
 * @head: A pointer to the pointer pointing to the first node in the list.
 * @n: The data to be added in the node.
 *
 * Return: The address of the new node, or NULL on failure.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *tmp;
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;

	if (*head == NULL)
	{
		*head = new;
		(*head)->next = NULL;
	}
	else
	{
		tmp = *head;
		*head = new;
		(*head)->next = tmp;
	}

	return (*head);
}
