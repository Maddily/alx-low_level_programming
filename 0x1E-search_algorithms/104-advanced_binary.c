#include "search_algos.h"

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
		if (middle_index == start_index || array[middle_index - 1] != value)
			return (middle_index);

		end_index = middle_index;
	}

	if (array[middle_index] >= value)
		return (binary_search_helper(array, start_index, middle_index, value));
	else
		return (binary_search_helper(array, middle_index + 1, end_index, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers,
 * using the Advanced Binary search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @size: The size of the array.
 * @value: The value to be searched for.
 *
 * Return: The first index where the value is located,
 * or -1 if the value isn't found or if the array is NULL.
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t start_index = 0, end_index = size - 1;

	if (array == NULL)
		return (-1);

	return (binary_search_helper(array, start_index, end_index, value));
}
