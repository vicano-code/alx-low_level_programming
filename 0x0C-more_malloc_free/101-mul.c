#include <stdlib.h>
#include "main.h"
/**
 * _mul - multiplies two positive numbers
 * @argc: number of arguments including the func name
 * @argv: the arguments
 * Return: nothing
 */

void _mul(int argc, char *argv)
{
	char result;

	if (argc != 3)
	{
		_putchar("Error\n");
		exit(98);
	}

	for (i = 1; i <= argc; i++)
	{
		for (j = 0; j < _numlen(argv[i]); j++)
		{
			if (!(isdigit(argv[i][j])))
			{
				_putchar("Error\n");
				exit(98);
			}
		}
	}

	result = atoi(arg[1]) * atoi(arg[2]);
	_putchar(result);
	_putchar('\n');
}
