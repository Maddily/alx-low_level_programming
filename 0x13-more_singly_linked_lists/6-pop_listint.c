#include "lists.h"

/**
 * pop_listint - Deletes the first node in a list
 * @head: A pointer to the pointer pointing to the first node in a list.
 *
 * Return: The deleted node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	if (*head == NULL)
		return (0);

	current = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = current;

	return (n);
}
