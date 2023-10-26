#include "main.h"

/**
 * flip_bits - the number of bits you would need to flip to
 * get from one number to another
 * @n: first number
 * @m: second number
 * Return: the number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int diff_bits;
	unsigned long int diff;

	diff_bits = 0;
	/* find the Xor betwen nums to show bit 1 if different bits */
	diff = n ^ m;

	/* shift diff to right and tally the ones up */
	do {
		diff_bits += (diff & 1);
		diff >>= 1;
	} while
		(diff > 0);

	return (diff_bits);
}

