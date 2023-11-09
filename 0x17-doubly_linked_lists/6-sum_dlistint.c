#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all the data in a list
 *
 * @head: A pointer to the first node in the list
 *
 * Return: The sum
*/
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum = 0;

	current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
