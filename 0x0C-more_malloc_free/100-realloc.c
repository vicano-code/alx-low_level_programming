#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to memory previously allocated
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 * Return: nothing
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, size;
	void *newptr;

	/* input validation */
	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		else
			return (newptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	/* new memory allocation and validation*/
	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	/* ensure extra memory is not initialized if new_size > old_size */
	if (new_size < old_size)
		size = new_size;
	else
		size = old_size;

	/* reallocate memory */
	for (i = 0; i < size; i++)
		*((char *)newptr + i) = *((char *)ptr + i);
	free(ptr); /* free old ptr */
	return (newptr);
}
