#include <stdlib.h>
#include "main.h"

/**
 * _strlen - compute string length
 * @str: the string
 * Return: string length value
 */

int _strlen(char *str)
{
	int strlen = 0;

	while (*(str + strlen) != '\0')
		strlen++;
	return (strlen);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: succss-pointer to concatenated string;
 * NULL to failure
 * if NULL is passed to s1 or s2 treat as empty string
 */

char *str_concat(char *s1, char *s2)
{
	char *newstr;
	int strlen1, strlen2;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* find length of s1 and s2*/
	strlen1 = _strlen(s1);
	strlen2 = _strlen(s2) + 1; /* add 1 for null termination */

	/* allocate memory */
	newstr = malloc((strlen1 + strlen2) * sizeof(char));
	if (newstr == NULL) /* validate memory */
		return (NULL);

	/* concatenate s1 and s2 */
	i = 0, j = 0;
	while (i < strlen1)
	{
		*(newstr + i) = *(s1 + i);
		i++;
	}
	while (i <= (strlen1 + strlen2)) /* include null terminator */
	{
		*(newstr + i) = *(s2 + j);
		i++, j++;
	}

	return (newstr);
}
