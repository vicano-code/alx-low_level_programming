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

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(ptr) * n) ;
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		*(ptr + i) = min;
		min++;
	}

	return (ptr);
}
