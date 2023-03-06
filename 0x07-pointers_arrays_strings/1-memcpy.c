#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: destination memory address
 * @src: source memory address
 * @n: number of bytes to be copied
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char **ptr;

	ptr = &dest;
	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			*(dest + i) = *(src + i);
		}
	}

	return (*ptr);
}
