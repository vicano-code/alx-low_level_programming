#include "main.h"
#include <stdlib.h>

/**
 * free_grid -  frees a 2D grid previously
 * created by your alloc_grid function
 * @grid: pointer to the 2D array
 * @height: height of array
 */

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		free(grid);

	for (i = 0; i < height; i++)
	{
		if (grid[i] == NULL)
			free(grid);
	}

	free(grid);
}
