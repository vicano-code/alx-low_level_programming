#include <stdio.h>

/**
 * main - print numbers
 * Return: Always 0 (success)
 */

int main(void)
{
	int num  = '0';

	while (num < '10')
	{
		putchar(num);
		num++;
	}
	putchar('\n');

	return (0);
}
