#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and
 * initializes it with a specific char
 * @size: array size
 * @c: char to initialize
 * Return: a pointer to the array, or NULL if it fails
 * or NULL if size = 0
 */

char *create_array(unsigned int size, char c)
{
	int i = 0;
	char *arr;

	if (size <= 0)
		return (NULL);
	arr = malloc(size * sizeof(char)); /* allocate memory */

	if (arr == NULL) /* validate memory */
		return (NULL);

	while (i < (int)size)
	{
		*(arr + i) = c;
		i++;
	}
	*(arr + i) = '\0';

	return (arr);
}
