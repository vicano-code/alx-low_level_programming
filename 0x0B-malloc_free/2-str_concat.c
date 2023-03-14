#include <stdlib.h>
#include "main.h"

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

	/* find length of s1 */
	strlen1 = 0;
	while (*(s1 + strlen1) != '\0')
	{
		strlen1++;
	}
	/* find length of s2 */
	strlen2 = 0;
	while (*(s2 + strlen2) != '\0')
	{
		strlen2++;
	}

	/* allocate memory */
	newstr = malloc((strlen1 + strlen2) * sizeof(char));

	if (newstr == NULL) /* check for insufficient memory */
		return (NULL);

	/* concatenate s1 and s2 */
	i = 0;
	while (i < strlen1)
	{
		*(newstr + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (i <= (strlen1 + strlen2))
	{
		*(newstr + i) = *(s2 + j);
		i++;
		j++;
	}

	return (newstr);
}
