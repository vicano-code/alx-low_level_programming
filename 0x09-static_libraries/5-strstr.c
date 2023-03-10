#include "main.h"
#define NULL 0

/**
 * _strstr - finds the first occurrence of the
 * substring needle in the string haystack
 * @haystack: strng to search
 * @needle: substring to find in haystack
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j, k;
	int start;

	if (needle[0] == '\0')
		return (haystack);

	/* count num of bytes in substring */
	i = 0;
	while (needle[i] != '\0')
	{
		i++;
	}

	/* match needle to haystack */
	j = 0;
	while (*(haystack + j) != '\0')
	{
		if (haystack[j] == needle[0])
		{
			start = j;
			k = 1;
			while (*(needle + k) != '\0')
			{
				if (haystack[start + k] == needle[k])
					k++;
				else
					break;
			}
			if (needle[k] == '\0')
				return (haystack + start);
		}
		j++;
	}
	return (NULL);
}
