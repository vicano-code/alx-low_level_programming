#include <stdlib.h>
#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
		len++, s++;

	return (len);
}

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: first argument
 * @av: pointer to second argument
 * Return: pointer to new string or NULL if fails and
 * NULL if ac == 0 or av == NULL
 */

char *argstostr(int ac, char **av)
{
	int i, j, k, n;
	int len = 0;
	char *newstr;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len += _strlen(av[i]);
	}
	len += ac + 1; /* add space for newline and null terminator */

	newstr = malloc(sizeof(char) * len);
	if (newstr == NULL)
	{
		free(newstr);
		return (NULL);
	}
	
	n = 0;
	for (j = 0; j < ac; j++)
	{
		for (k = 0; k < _strlen(av[j]); k++)
		{
			newstr[n++] = av[j][k];
		}
		newstr[n++] = '\n';
	}

	return (newstr);
}
