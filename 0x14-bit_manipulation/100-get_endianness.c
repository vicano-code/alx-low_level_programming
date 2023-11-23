#include "main.h"

/**
 * get_endianness - C program to find out if the underlying
 * architecture is little endian or big endian
 * Return: 0 if big endian, 1 if little endian
 */


int get_endianness(void)
{
	unsigned int x = 1;
	unsigned char *c = (unsigned char *) &x;

	if (*c == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
