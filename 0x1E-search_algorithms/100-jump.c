#include "search_algos.h"

/**
 * find_min - Finds the minimum of two numbers.
 *
 * @a: The first number
 * @b: The second number
 *
 * Return: The smaller number.
*/
size_t find_min(size_t a, size_t b)
{
	return ((a < b) ? a : b);
}

/**
 * jump_search - Searches for a value in a sorted array of integers,
 * using the Jump search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @size: The size of the array.
 * @value: The value to be searched for.
 *
 * Return: The first index where the value is located,
 * or -1 if the value isn't found or if the array is NULL.
*/
int jump_search(int *array, size_t size, int value)
{
	size_t high = sqrt(size);
	size_t low = 0;

	if (array == NULL)
		return (-1);

	while (array[low] < value && array[high] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", low, array[low]);

		low = high;
		high += sqrt(size);

		if (low >= size)
			return (-1);
		if (high >= size)
			break;
	}

	printf("Value checked array[%ld] = [%d]\n", low, array[low]);
	printf("Value found between indexes [%ld] and [%ld]\n", low, high);

	while (low < size && array[low] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", low, array[low]);

		low++;

		if (low == size)
			return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", low, array[low]);

	if (low < size && array[low] == value)
		return (low);

	return (-1);
}
