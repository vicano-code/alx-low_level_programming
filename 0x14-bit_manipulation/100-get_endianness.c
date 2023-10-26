#include "main.h"

/**
 * get_endianness - C program to find out if the underlying
 * architecture is little endian or big endian
 * Return: 0 if big endian, 1 if little endian
 */


int get_endianness(void)
{
	unsigned int x = 0x76543210;
	char *c = (char *) &x;

	if (*c == 0x10)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

