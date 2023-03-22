#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - computes sum of two numbers
 * @a: first number
 * @b: second number
 * Return: the result
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - computes the difference of two numbers
 * @a: first number
 * @b: second number
 * Return: the result
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - computes the product of two numbers
 * @a: first number
 * @b: second number
 * Return: the result
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - computes the division of two numbers
 * @a: first number
 * @b: second number
 * Return: the result
 */

int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - computes the remainder of the division of two numbers
 * @a: first number
 * @b: second number
 * Return: the result
 */

int op_mod(int a, int b)
{
	return (a % b);
}
