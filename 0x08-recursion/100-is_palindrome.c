#include "main.h"

/**
 * _strlen - recursively find last index of string
 * @s: the string
 * @count: index variable
 * Return: the last index
 */

int _strlen(char *s, int count)
{
	if (*(s + count) == '\0')
		return (0);

	count++;
	return (1 + _strlen(s, count));
}

/**
 * is_pali - recursively checks if string is a palindrome
 * @s: the string
 * @i: forward index
 * @j: backward index
 * Return: 1 if a string is a palindrome and 0 if not
 */

int is_pali(char *s, int i, int j)
{
	if (i >= j)
		return (1);

	if (s[i] == s[j])
	{
		i++;
		j--;
		return (is_pali(s, i, j));
	}

	return (0);
}

/**
 * is_palindrome - checks if string is a palindrome
 * @s: the string
 * Return: 1 if a string is a palindrome and 0 if not
 */

int is_palindrome(char *s)
{
	int count = 0;
	int i = 0;
	int j = _strlen(s, count) - 1;

	return (is_pali(s, i, j));
}
