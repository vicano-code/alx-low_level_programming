#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory address to fill
 * @b: constant byte
 * @n: first n bytes of memory
 * Return: pointer to memory area, s
 */

char *_memset(char *s, char b, unsigned int n)
{
	if (n > 0)
	{
		unsigned int i;

		for (i = 0; i < n; i++)
		{
			s[i] = b;
		}
	}

	return (s);
}
