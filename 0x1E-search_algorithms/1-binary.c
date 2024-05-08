#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return:  first index where value is located or NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i = 0;
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", (int)i);
	while (left < right)
	{
		mid = floor((left + right) / 2);
		if (array[mid] < value)
		{
			left = mid + 1;
			printf("Searching in array: ");
			for (i = left; i < right; i++)
				printf("%d, ", array[i]);
			printf("%d\n", (int)i);
		}
		else if (array[mid] > value)
		{
			right = mid - 1;
			printf("Searching in array: ");
			for (i = left; i < right; i++)
				printf("%d, ", array[i]);
			printf("%d\n", (int)i);
		}
		else
			return (mid);
	}
	return (-1);
}
