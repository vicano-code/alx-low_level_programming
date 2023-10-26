#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long ncopy;

	if (n == 0)
		_putchar('0');

	ncopy = n;
	/* count of num of bits required to represent n */
	while (ncopy > 0)
	{
		ncopy >>= 1;
		count++;
	}

	/* loop through each bit of the number */
	for (i = count - 1; i >= 0; i--)
	{
		_putchar((n >> i) & 1  ? '1' : '0');
	}
	_putchar('\n');
}
