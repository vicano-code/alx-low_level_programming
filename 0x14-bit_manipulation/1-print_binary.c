#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: the number
 * Return: nothing
 */

void print_binary(unsigned long int n)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		_putchar(n & (1 << i) ? '1' : '0');
	}
	_putchar('\n');
}
