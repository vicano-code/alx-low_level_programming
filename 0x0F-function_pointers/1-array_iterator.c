#include <stddef.h>
#include "function_pointers.h"
#include <stdlib.h>
/**
 * array_iterator - executes a function given as a
 * parameter on each element of an array
 * @array: pointer to array
 * @size: size of array
 * @action: pointer to the function
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i; /* match data type */

	if (array != NULL && action != NULL) /* validate input */
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
