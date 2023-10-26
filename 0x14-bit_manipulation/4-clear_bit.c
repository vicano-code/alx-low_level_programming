#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @index: the index, starting from 0 of the bit
 * @n: number to set bit
 * Return: 1 if successful or -1 if error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;
	unsigned int max_index;

	/* validate index not out of range */
	max_index = sizeof(unsigned long int) * 8;
	if (index > max_index)
		return (-1);

	/* right shift index to set bit */
	mask = ~(mask << index);
	*n = (*n & mask);

	return (1);
}

