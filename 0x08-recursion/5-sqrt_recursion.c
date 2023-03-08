#include "main.h"

/**
 * get_root - helper function to compute
 * the natural square root of a number
 * @n: the number
 * @x: seed
 * Return: the result
 */

int get_root(int n, int x)
{
	if (x * x > n)
		return (-1);
	if (x * x == n)
		return (x);

	return (get_root(n, x + 1));
}

/**
 * _sqrt_recursion - Computes the natural square root of a number
 * @n: the number
 * Return: the result
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (get_root(n, 0));
}
