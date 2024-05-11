#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array
 * @left: lowest index of binary sub-array
 * @right: highest index of binary sub-array
 * @value: value to search for
 * Return:  first index where value is located or NULL
 */
int advanced_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	size_t i;

	if ( left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = left + (right - left) / 2;
		
		if (array[mid] == value && (mid == 0 || array[mid - 1] < value))
			return (mid);
		
		if (array[mid] > value)
			return (advanced_binary_search(array, left, mid - 1, value));

		if (array[mid] < value)
			return (advanced_binary_search(array, mid + 1, right, value));
	}
	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * the basic binary search does not necessarily return the index of the
 * first value in the array
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return:  first index where value is located or NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_search(array, left, right, value));
}
