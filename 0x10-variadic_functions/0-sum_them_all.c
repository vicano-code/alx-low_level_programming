#include <stdlib.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - computes the sum of all its parameters
 * @n: number of parameters
 * @...: other parameters
 * Return: the sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum;

	/* initialize the argument */
	va_start(ap, n);

	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(ap, int); /* get the next argument value */

	va_end(ap); /* clean up */
	return (sum);
}

