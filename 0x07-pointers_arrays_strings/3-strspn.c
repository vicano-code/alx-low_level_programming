#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to string
 * @accept: number of bytes of substring
 * Return: the number of bytes in the initiail segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, num_byte = 0;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				num_byte++;
				break;
			}
		}
		if (*(s + i) != *(accept + j))
			break;
	}
	return (num_byte);
}
