#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - Creates a two dimensional array of integers
 * @width: The column count
 * @height: The row count
 * Return: A pointer to the array
 */
int **alloc_grid(int width, int height)
{
	int **grid, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));

		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[i]);

			free(grid);

			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
