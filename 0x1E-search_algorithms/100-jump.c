#include "search_algos.h"

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
	size_t a = 0;
	size_t b = step;
	/*size_t last_idx = size - 1;*/

	/* validate array and size */
	if (!array || size == 0)
		return (-1);

	/* locate block containing value */
	while (a <= size)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (b < size && array[b] < value)
		{
			a = b;
			b += step;
		}
		else
		{
			printf("Value found between indexes [%lu] and [%lu]\n", a, b);
			break;
		}
	}
	/* search value in block */
	while (a <= b)
	{
		if (a >= size)
			break;
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
			return (a);

		a++;
	}
	return (-1);
}
