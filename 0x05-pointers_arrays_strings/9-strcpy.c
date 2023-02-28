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
	int i;

	i = 0;
	while (*(src + i) != 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
