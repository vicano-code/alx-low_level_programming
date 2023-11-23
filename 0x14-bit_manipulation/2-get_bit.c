#include "main.h"

/**
 * get_bit - gives the value of a bit at a given index
 * @index: the index, starting from 0 of the bit
 * @n: number to find bit
 * Return: the value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;
	unsigned int max_index;

	/* validate index not out of range */
	max_index = sizeof(unsigned long int) * 8;
	if (index > max_index)
		return (-1);

	/* right shift index to find bit */
	bit = ((n >> index) & 1);

	return (bit);
}
