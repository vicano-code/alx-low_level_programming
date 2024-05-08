#include "search_algos.h"

/**
 * min - get the minimum of two integers
 * @a: first number
 * @b: second number
 * Return: the minimum value
 */
size_t min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

/**
 * jump_search -  searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located or -1 if NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;

	if (array[step] > value)
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	/* finding the block where value may be located */
	while (array[min(step, size) - 1] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (prev >= size || array[step] > value)
		{
			prev -= (int)sqrt(size);
			step -= (int)sqrt(size);
			break;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev, step);

	/* searching for value in the block */
	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev++;
		if (prev >= size)
			return (-1);
	}
	if (array[prev] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		return (prev);
	}

	return (-1);
}
