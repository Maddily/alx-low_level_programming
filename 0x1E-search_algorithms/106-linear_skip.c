#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: A pointer to the head of a skip list.
 * @value: The value to be searched for.
 *
 * Return: A pointer to the first node where the value is located,
 * or NULL if the value isn't found or if the head node is NULL.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *temp;

	if (list == NULL)
		return (NULL);
	while (current->express != NULL)
	{
		if (current->express->n >= value)
		{
			printf("Value checked at index [%ld] = [%d]\n",
				current->express->index, current->express->n);
			printf("Value found between indexes [%ld] and [%ld]\n",
				current->index, current->express->index);
			while (current->next != NULL)
			{
				printf("Value checked at index [%ld] = [%d]\n",
					current->index, current->n);
				if (current->n == value)
					return (current);
				current = current->next;
			}
		}
		current = current->express;
		printf("Value checked at index [%ld] = [%d]\n",
			current->index, current->n);
	}
	temp = current;
	while (temp->next != NULL)
		temp = temp->next;
	printf("Value found between indexes [%ld] and [%ld]\n",
		current->index, temp->index);
	while (current->next != NULL && current->n != value)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			current->index, current->n);
		current = current->next;
	}
	printf("Value checked at index [%ld] = [%d]\n",
		current->index, current->n);
	return (current->n == value ? current : NULL);
}
