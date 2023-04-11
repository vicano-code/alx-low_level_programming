#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int i, len = 0;
	unsigned long int ncopy = n;

	while (ncopy > 0)
	{
		len++;
		ncopy >>= 1;
	}
	len--;
	if (ncopy == 0)
		_putchar('0');

	for (i = len; i >= 0; i--)
	{
		_putchar(((ncopy >> i) & 1) ? '1' : '0');
	}
	_putchar('\n');
}
