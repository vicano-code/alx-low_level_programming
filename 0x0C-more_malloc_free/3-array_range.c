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

	if (min > max)
		return (NULL);

	ptr = malloc((max - min + 1) * sizeof(ptr));
	if (ptr == NULL)
		return (NULL);

	for (i = min; i <= max; i++)
	{
		*(ptr + i) = i;
		i++;
	}

	return (ptr);
}
