#include "lists.h"

/**
 * free_listint2 - Frees a list.
 * @head: A pointer to the pointer pointing to the first node in the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL || *head == NULL)
		return;

	current = *head;
	while (*head != NULL)
	{
		*head = (*head)->next;
		free(current);
		current = *head;
	}
	*head = NULL;
}
