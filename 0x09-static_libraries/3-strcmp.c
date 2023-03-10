#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string to be compared
 * @s2: string to be compared
 * Return: -1 if s1 less than s2, 0 if equal
 * and 1 if s1 greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
