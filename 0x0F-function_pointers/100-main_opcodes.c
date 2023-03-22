#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 - succesful
 */

int main(int argc, char **argv)
{
	int i, bytes;
	char *addr;

	/* validate for required number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* validate for non-negative bytes */
	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	addr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx ", addr[i]);
	}
	printf("%02hhx\n", addr[i]);

	return (0);

}
