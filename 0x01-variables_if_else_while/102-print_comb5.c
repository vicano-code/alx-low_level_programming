#include <stdio.h>

/**
 * main - print two two digit pairs in range 00-99 (00 01, 00,02,...) 
 * Return: Always 0 (success)
 */

int main(void)
{
	int tens;
	int unit;
	int tens1;
	int unit1;

	for (tens = '0'; tens <= '9'; tens++)
	{
		for (unit = 0; unit <= '9'; unit++)
		{
			for (tens1 = tens; tens1 <= '9'; tens1++)
			{
				for (unit1 = (unit + 1); unit1 <= '9'; unit1++)
				{
					putchar(tens);
					putchar(unit);
					putchar(' ');
					putchar(tens1);
					putchar(unit1);

					if (!((tens == '9' && unit == '8') && (tens1 == '9' &&  unit1 == '9')))
					{
						putchar(',');
						putchar(' ');
					}
				}
				unit1 = '0';
			}
		}
	}

	putchar('\n');

	return (0);
}
