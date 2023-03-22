#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - program that performs simple operations
 * @argc: number of arguments + output name
 * @argv: array of arguments
 * Return: result
 */

int main(int argc, char **argv)
{
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);
	char *operator = argv[2];
	int p;

	/* input validation */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (get_op_func(operator) == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*operator == '/' || *operator == '%') && num2 == '0')
	{
		printf("Error\n");
		exit(100);
	}

	p = get_op_func(operator)(num1, num2);

	printf("%d\n", p);
	return (0);
}
