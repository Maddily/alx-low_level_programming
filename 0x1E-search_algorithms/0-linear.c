#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers,
 * using Linear Search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @size: The size of the array.
 * @value: The value to be searched for.
 *
 * Return: The first index where the value is located,
 * or -1 if the value isn't found or if the array is NULL.
*/
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}
