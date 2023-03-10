#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - a program that multiplies two numbers
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 - successful, 1-error
 */

int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a * b);
	return (0);
}
