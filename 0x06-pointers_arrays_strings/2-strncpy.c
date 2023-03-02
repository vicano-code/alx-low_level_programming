#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination of copied string
 * @src: string to copy
 * @n: 
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;

	for (i=0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
