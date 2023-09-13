#include "function_pointers.h"

/**
 * array_iterator - Executes the function pointed at
 * by action pointer on each array element
 * @array: A pointer to an array of integers
 * @size: The size of the array
 * @action: A pointer to a function
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
}
