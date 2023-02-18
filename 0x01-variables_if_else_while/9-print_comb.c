#include <stdio.h>

/**
 * main - print numbers with comma and space
 * Return: Always 0 (success)
 */

int main(void)
{
	int num  = 0;

	while (num <= 9)
	{
		putchar(num);
		if (num < 9)
		{
			putchar(',');
			putchar(' ');
		}
		num++;
	}
	putchar('\n');

	return (0);
}
