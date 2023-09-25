#include "lists.h"

/**
 * sum_listint - Sums all of the data in a list
 * @head: A pointer to the first node in a list.
 *
 * Return: The sum of all of the data in the list.
 */
int sum_listint(listint_t *head)
{
	listint_t *current;
	int sum = 0;

	if (head == NULL)
		return (0);

	current = head;
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
