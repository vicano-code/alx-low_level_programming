#include <stdlib.h>
#include "main.h"

/**
 * _strlen - calculate and return string length
 * @string: string
 * Return: string length
 */

int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
		i++;
	return (i);
}

/**
 * string_nconcat - concatenates two strings
 * @s1: pointer first string
 * @s2: pointer to second string
 * @n: number of bytes of s2 to be concatenated
 * Return: pointer to concatenated string allocated memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *newstr;
	unsigned int len, len1, len2, i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1); /* get string length of s1 & s2 */
	len2 = _strlen(s2);
	if (n >= len2) /* manage memory if n is >= length of s2 */
		n = len2;
	len = len1 + n + 1;
	newstr = malloc(sizeof(*newstr) * len); /* allocate memory */
	if (newstr == NULL) /* validate memory */
		return (NULL);
	/* concatenate */
	while (i < len1)
	{
		*(newstr + i) = *(s1 + i);
		i++;
	}
	while (j < n)
	{
		*(newstr + i) = *(s2 + j);
		i++, j++;
	}
	*(newstr + i) = '\0';
	return (newstr);
}
