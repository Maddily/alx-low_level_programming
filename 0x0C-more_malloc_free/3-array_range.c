#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers
 * @min: The first integer
 * @max: The last integer
 * Return: A pointer to an array of integers
 */
int *array_range(int min, int max)
{
	int *arr, i, n;

	if (min > max)
		return (NULL);

	n = max - min + 1;

	arr = malloc(n * sizeof(int));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < n; i++, min++)
		arr[i] = min;

	return (arr);
}
