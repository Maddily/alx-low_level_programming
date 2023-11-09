#include "lists.h"

/**
 * free_dlistint - Frees a list
 *
 * @head: A pointer to the first node in the list
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
