#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements of array
 * @size: size byts of each element
 * Return: pointer to the allocated memory or NULL if fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void **arr;

	/* input validation */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* allocate memory and check for error */
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);

	/* set memmory allocated values to 0 */
	for (i = 0; i < nmemb * size; i++)
	{
		*((char *)arr + i) = 0;
	}

	return (arr);
}
