#include "lists.h"

/**
 * free_listint - Frees a list.
 * @head: A pointer to the first node in the list.
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (head != NULL)
	{
		head = head->next;
		free(current);
		current = head;
	}
}
