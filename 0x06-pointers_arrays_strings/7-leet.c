#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 * Return: encoded string
 */

char *leet(char *s)
{
	int i, j;

	int p[11] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	int q[11] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 11; j++)
		{
			if (s[i] == p[j])
				s[i] = q[j];
		}
	}

	return (s);
}
