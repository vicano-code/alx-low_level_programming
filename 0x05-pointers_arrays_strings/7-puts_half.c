#include "main.h"

/**
 * puts_half -  prints half of a string, followed by a new line
 * @str: input string
 */

void puts_half(char *str)
{
	int strLen;
	int n;
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	strLen = i;
	n = (strLen - 1) / 2;

	while (*(str + n + 1) != '\0')
	{
		_putchar(*(str + n + 1));
		n++;
	}

	_putchar('\n');
}
