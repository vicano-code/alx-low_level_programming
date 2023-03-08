#include "main.h"

/**
 * is_prime - recursively divide by higher divisor, skip even nums
 * @n: number to check if prime
 * @x: divisor
 * Return: 1 if prime, 0 if not, or recursive function call
 */

int is_prime(int n, int x)
{
	if (x == n)
		return (1);
	if (n % x == 0)
                return (0);

	return (is_prime(n, x + 1));
}

/**
 * is_prime_number - check if prime
 * @n: number to check
 * Return: 1 if prime, 0 if not
 */

int is_prime_number(int n)
{
	if (n < 2 || n % 2 == 0)
		return (0);
	if (n == 2)
		return (1);
	return (is_prime(n, 3));
}
