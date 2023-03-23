#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - function that prints strings
 * @separator: string to be printed between the strings
 * @n: number of strings passed to the function
 * Return: nothing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strlist;
	unsigned int i;
	char *str;

	if (n > 0)
	{
		va_start(strlist, n);
		for (i = 0; i < n; i++)
		{
			str = va_arg(strlist, char *);
			if (!str)
				printf("(nil)");
			else
				printf("%s", str);
			if (separator && i < n - 1)
				printf("%s", separator);
		}
		va_end(strlist);
	}
	printf("\n");
}
