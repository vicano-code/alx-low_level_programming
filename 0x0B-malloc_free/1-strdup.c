#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a new string which is
 * a duplicate of the string str
 * @str: string to be duplicated
 * Return: NULL if str = NULL;Success-returns pointer to
 * duplicated string; NULL if insufficient memory
 */

char *_strdup(char *str)
{
	char *s;
	int i, j;

	i = 0;
	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		i++;
	}

	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	j = 0;
	while (j < i)
	{
		*(s + j) = *(str + j);
		j++;
	}

	return (s);
}
