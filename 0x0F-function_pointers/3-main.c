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
	int (*ptr)(int, int);
	int p;

	ptr = get_op_func(operator);

	/* input validation */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (ptr == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*operator == '/' || *operator == '%') && num2 == '0')
	{
		printf("Error\n");
		exit(100);
	}

	p = (*ptr)(num1, num2);

	printf("%d\n", p);
	return (0);
}
