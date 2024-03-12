#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers,
 * using the Jump search algorithm.
 *
 * @list: A pointer to the head of a list.
 * @size: The size of the list.
 * @value: The value to be searched for.
 *
 * Return: A pointer to the first node where the value is located,
 * or NULL if the value isn't found or if the head node is NULL.
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *low = list, *high = list;

	if (list == NULL)
		return (NULL);
	while (high->index < step)
		high = high->next;
	while (low->n < value && high->n < value
		&& low->next != NULL && high->next != NULL)
	{
		while (low->index < step)
			low = low->next;
		printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);
		step += sqrt(size);
		while (high->index < step && high->next != NULL)
			high = high->next;
		if (low->index >= size)
			return (NULL);
		if (high->index >= size)
			break;
	}
	printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
	printf("Value found between indexes [%ld] and [%ld]\n",
		low->index, high->index);

	while (low->index < size && low->n < value
		&& low->next != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);

		low = low->next;
		if (low->index == size)
			return (NULL);
	}

	printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);

	if (low->index < size && low->n == value)
		return (low);
	return (NULL);
}
