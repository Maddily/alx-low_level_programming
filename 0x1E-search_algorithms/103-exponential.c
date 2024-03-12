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
 * print_array - Prints an array.
 *
 * @array: A pointer to the first element in an array of integers.
 * @start_index: The starting index.
 * @end_index: The ending index.
*/
void print_array(int *array, int start_index, int end_index)
{
	int i;

	printf("Searching in array: ");
	for (i = start_index; i <= end_index; i++)
	{
		if (i == end_index)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
 * binary_search_helper - Searches for a value, recursively,
 * using the Binary search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @start_index: The starting index.
 * @end_index: The ending index.
 * @value: The value to be searched for.
 *
 * Return: The index where the value is located,
 * or -1 if the value isn't found.
*/
int binary_search_helper(int *array, int start_index, int end_index, int value)
{
	int middle_index = (start_index + end_index) / 2;

	if (start_index > end_index)
		return (-1);

	print_array(array, start_index, end_index);

	if (array[middle_index] == value)
	{
		return (middle_index);
	}
	else if (array[middle_index] > value)
	{
		end_index = middle_index - 1;
		return (binary_search_helper(array, start_index, end_index, value));
	}
	else if (array[middle_index] < value)
	{
		start_index = middle_index + 1;
		return (binary_search_helper(array, start_index, end_index, value));
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers,
 * using the Exponential search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @size: The size of the array.
 * @value: The value to be searched for.
 *
 * Return: The first index where the value is located,
 * or -1 if the value isn't found or if the array is NULL.
*/
int exponential_search(int *array, size_t size, int value)
{
	size_t index;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	index = 1;
	while (index < size && array[index] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		index *= 2;
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		index / 2, find_min(index, size - 1));

	return (binary_search_helper
		(
			array, index / 2, find_min(index, size - 1), value)
		);
}
