#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <ctype.h>

/**
 * _strlen - compute string length
 * @s: pointer to string
 * Return: the result
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}

/**
 * main - a program that adds positive numbers
 * @argc: argument count
 * @argv: array of arguments
 * Return:  0 - success, 1-error
 */

int main(int argc, char *argv[])
{
	int i, j, sum;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		/* if (!(*argv[i] >= '0' && *argv[i] <= '9')) */
		for (j = 0; j < _strlen(argv[i]); j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
