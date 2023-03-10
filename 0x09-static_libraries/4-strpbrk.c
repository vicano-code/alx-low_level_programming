#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search for a match
 * @accept: string to match any of the bytes
 * Return: pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int i, j, k, a;

	k = 0;
	while (*(s + k) != '\0')
	{
		k++;
	}
	a = k; /* a for first match, starting from k */

	for (i = 0; *(accept + i) != '\0'; i++)
	{
		for (j = 0; *(s + j) != '\0'; j++)
		{
			if (*(s + j) == *(accept + i))
			{
				if (j < a)
					a = j;
			}
		}
	}
	if (a < k)
		return (s + a);
	else
		return (NULL);
}
