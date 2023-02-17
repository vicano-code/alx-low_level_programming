#include <stdio.h>

/**
 * main - print numbers
 * Return: Always 0 (success)
 */

int main(void)
{
	int num  = 0;

	while (num < 10)
	{
		printf("%i", num);
		num++;
	}
	putchar('\n');

	return (0);
}
