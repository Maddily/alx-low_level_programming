#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers,
 * using the Interpolation search algorithm.
 *
 * @array: A pointer to the first element in an array of integers.
 * @size: The size of the array.
 * @value: The value to be searched for.
 *
 * Return: The first index where the value is located,
 * or -1 if the value isn't found or if the array is NULL.
*/
int interpolation_search(int *array, size_t size, int value)
{
	int index, low_index = 0, high_index = size - 1;

	if (array == NULL)
		return (-1);

	while (low_index <= high_index
		&& value >= array[low_index]
		&& value <= array[high_index])
	{
		if (low_index == high_index)
		{
			if (array[low_index] == value)
				return (low_index);

			printf("Value checked array[%d] is out of range\n", low_index);
			return (-1);
		}
		index = low_index +
		(
			((double)(high_index - low_index) / (array[high_index] - array[low_index]))
			* (value - array[low_index])
		);

		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		else if (array[index] < value)
			low_index = index + 1;
		else
			high_index = index - 1;
	}
	index = low_index +
	(
		((double)(high_index - low_index) / (array[high_index] - array[low_index]))
		* (value - array[low_index])
	);

	printf("Value checked array[%d] is out of range\n", index);
	return (-1);
}
