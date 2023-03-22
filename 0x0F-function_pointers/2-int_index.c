#include <stddef.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: the array
 * @size: number of elements in the array
 * @cmp: a pointer to the function to be used to compare values
 * Return: the index of the first element for which
 * the cmp function does not return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	/* validate input */
	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	/* do search */
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);

}
