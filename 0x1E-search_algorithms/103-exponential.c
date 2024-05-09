#include "search_algos.h"

/**
 * _binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array
 * @left: start index of sub array
 * @right: end index of sub array
 * @value: value to search for
 * Return:  first index where value is located or NULL
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i = 0;
	size_t mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (int)(left + (right - left) / 2);
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 *  using the Exponential search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located or -1 if NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t step = 2;
	size_t a = 1;
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
			b *= step;
		}
		else
		{
			if (b > size - 1)
				b = size - 1;
			printf("Value found between indexes [%lu] and [%lu]\n", a, b);
			break;
		}
	}
	/* search value in subarray using binary search */
	return (_binary_search(array, a, b, value));
}
