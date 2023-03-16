#include <stdlib.h>
#include "main.h"
#include <ctype.h>

/**
 * _numlen - calculates number of digits in a number
 * @num: the number
 * Return: the numbr of digits
 */

int _numlen(char *num)
{
	int i = 0;
	
	while (num)
		i++;

	return (i);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments including the func name
 * @argv: the arguments
 * Return: nothing
 */

int main(int argc, char **argv)
{
	int i, j, k, val;
	char *result;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	for (i = 1; i <= argc; i++)
	{
		for (j = 0; j < _numlen(argv[i]); j++)
		{
			if (!(isdigit(argv[i][j])))
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				exit(98);
			}
		}
	}

	val = (atoi(argv[1]) * atoi(argv[2]));
	result = (char *)val;
	for (k = 0; k < _numlen(result); k++)
	{
		_putchar(result[k]);
	}
	_putchar('\n');
	return (0);
}
