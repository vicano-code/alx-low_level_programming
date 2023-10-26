#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number, or 0 if b is NULL or if
 * there is one or more chars in the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int ans = 0, pow = 1;
	int i, b_len;

	if (b == NULL)
		return (0);

	b_len = (int)strlen(b) - 1;

	for (i = b_len; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		if (b[i] == '1')
			ans += pow;
		pow *= 2;
	}

	return (ans);
}
