#include "main.h"

/**
 * _strcat - concatenates two strings
 * @src: string to concatenate
 * @dest: string to concatenate
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* obtain string size of dest */
	while (*(dest + i))
	{
		i++;
	}
	while (*(src + j))
	{
		dest[i + 1] = src[j];
		i++;
		j++;
	}

	return (dest);
}
