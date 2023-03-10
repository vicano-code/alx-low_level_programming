#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - a program that prints its name
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 - succesful
 */

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
