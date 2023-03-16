#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum integer value
 * @max: maximum integer value
 * Return: pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *ptr, i;
	int n = max - min + 1;

	/* input validation */
	if (min > max)
		return (NULL);

	/* memory allocation and validation */
	ptr = malloc(sizeof(ptr) * n);
	if (ptr == NULL)
		return (NULL);

	/* set array values to memory */
	for (i = 0; i < n; i++)
	{
		*(ptr + i) = min;
		min++;
	}

	return (ptr);
}
