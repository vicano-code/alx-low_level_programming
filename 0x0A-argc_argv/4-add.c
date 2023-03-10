#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - a program that adds positive numbers
 * @argc: argument count
 * @argv: array of arguments
 * Return:  0 - success, 1-error
 */

int main(int argc, char *argv[])
{
	int i, sum;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		if (!(*argv[i] >= '0' && *argv[i] <= '9'))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
