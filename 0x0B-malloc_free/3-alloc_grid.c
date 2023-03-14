#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - creates a 2 dimensional array of integers
 * @width: num of columns of array
 * @height: num of rows of array
 * Return: pointer to 2Darray, NULL if width or height
 * is 0 or negative
 */

int **alloc_grid(int width, int height)
{
	int i, j;
	int **arr;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = (int **)malloc(height * sizeof(int *));
	if (arr == NULL)
		return (NULL);
	for (i  = 0; i < width; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * height);
	}
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			arr[i][j] = 0;
		}
	}

	return (arr);
}
