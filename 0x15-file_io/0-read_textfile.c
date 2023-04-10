#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "_putchar.c"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer the variable holding the textfile
 * @letters: the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	int i;
	ssize_t bytes_read;
	char *ch;

	ch = malloc(sizeof(ch) * letters);
	if (filename == NULL) /*validate filename*/
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1) /*validate opening file*/
		return (0);

	bytes_read = read(fp, ch, letters);
	if(bytes_read == -1)
		return (0);

	for (i = 0; i < bytes_read; i++)
	{
		_putchar(ch[i]);
	}

	close(fp);

	return (bytes_read);
}
