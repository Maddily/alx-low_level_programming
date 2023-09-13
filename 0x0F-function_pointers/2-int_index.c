#include "function_pointers.h"

/**
 * int_index - Searches for a certain integer in an array of integers
 * @array: A pointer to an array of integers
 * @size: The size of the array
 * @cmp: A pointer to a function
 * Return: The index of the first element for which
 * the cmp function doesn't return 0,
 * or -1 if no element matches or if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
		if (size <= 0)
			return (-1);

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
