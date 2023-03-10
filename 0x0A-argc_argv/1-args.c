#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - a program that prints the number of
 * arguments passed to it
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 - successful
 */

int main(int argc, char *argv[])
{
	(void)argv; /* suppress unused argument error */

	printf("%d\n", argc - 1);

	return (0);
}
