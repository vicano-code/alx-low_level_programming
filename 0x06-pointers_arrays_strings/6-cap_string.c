#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string
 * Return: capitalized string,s
 */

char *cap_string(char *s)
{
	int i = 0;

	/* check first index for capital */
	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] = s[i] - 'a' + 'A';
	i++;

	while (*(s + i) != '\0')
	{
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
		{
			if (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n' ||
				       s[i - 1] == ',' || s[i - 1] == ';' ||
				       s[i - 1] == '.' || s[i - 1] == '!' ||
				       s[i - 1] == '?' || s[i - 1] == '"' ||
				       s[i - 1] == '(' || s[i - 1] == ')' ||
				       s[i - 1] == '{' || s[i - 1] == '}')
				*(s + i) = *(s + i) - 'a' + 'A';
		}
		i++;
	}
	return (s);
}
