#include "main.h"

/**
 * print_alphabet - print a-z, followed by a new line
 * Return: Always 0
 */

void print_alphabet_x10(void)
{
	char alpha;
	int count;

	for (count = 0; count < 10; count++)
	{
		for (alpha = 'a'; alpha <= 'z'; alpha++)
		{
			_putchar(alpha);	
		}
		_putchar('\n');
	}
	_putchar('\n');
}
