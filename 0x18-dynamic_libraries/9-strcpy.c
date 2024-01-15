#include "main.h"

/**
 * *_strcpy - Copy the given string
 * @dest: Location to copy string to
 * @src: String to copy
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}

	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}

	return (dest);
}
