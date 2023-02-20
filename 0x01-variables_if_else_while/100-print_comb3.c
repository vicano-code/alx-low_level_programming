#include <stdio.h>

/**
 * main - print all possible different combinations of two digits, 00-99, no duplicates(01 and 10) and combos (11,22)
 * Return: Always 0 (success)
 */

int main(void)
{
	int unit;
	int tens;

	for (tens = '0'; tens <= '9'; tens++)
	{
		for (unit = (tens + '1'); unit <= '9'; unit++)
		{
			putchar(tens);
			putchar(unit);

			if (tens != '8' || unit != '9')
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
