#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include "_putchar.c"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer the variable holding the textfile
 * @letters: the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char ch;
	FILE *fp;
	size_t count = 0;

	if (filename == NULL) /*validate filename*/
		return (0);

	fp = fopen(filename, "r");
	if (fp == NULL) /*validate opening file*/
		return (0);

	while ((count != letters) && (ch = fgetc(fp)) != EOF)
	{
		_putchar(ch);
		count++;
	}

	fclose(fp);

	return ((ssize_t)count);
}
