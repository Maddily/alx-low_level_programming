#include "lists.h"

/**
 * reverse_listint - Reverses a list.
 * @head: A pointer to the pointer pointing to the first node in the list.
 *
 * Return: A pointer to the first node in the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp1, *tmp2;

	if ((*head)->next == NULL)
		return (*head);

	tmp2 = NULL;
	while (*head != NULL)
	{
		tmp1 = (*head)->next;
		(*head)->next = tmp2;
		tmp2 = *head;
		*head = tmp1;
	}
	*head = tmp2;

	return (*head);
}
