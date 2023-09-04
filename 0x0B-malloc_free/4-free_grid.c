#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees a 2D grid
 * @grid: A 2D grid
 * @height: The grid's height
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
