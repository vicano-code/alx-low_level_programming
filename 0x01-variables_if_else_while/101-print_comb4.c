#include <stdio.h>

/**
 * main - print all possible two digits, no duplicates(01,10) and combos(11,22)
 * Return: Always 0 (success)
 */

int main(void)
{
	int unit;
	int tens;
	int hundreds;

	for (hundreds = '0'; hundreds <= '9'; hundreds++)
	{
		for (tens = (hundreds + 1); tens <= '9'; tens++)
		{
			for (unit = (tens + 1); unit <= '9'; unit++)
			{
				putchar(hundreds);
				putchar(tens);
				putchar(unit);

				if (hundreds != '7' || tens != '8' || unit != '9')
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
