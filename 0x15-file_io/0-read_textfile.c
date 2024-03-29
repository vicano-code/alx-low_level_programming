#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer the variable holding the textfile
 * @letters: the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp; /* file descriptor */
	ssize_t bytes_read, bytes_write;
	char *buffer;

	if (filename == NULL) /*validate filename*/
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1) /*validate opening file*/
		return (0);

	bytes_read = read(fp, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fp);
		return (0);
	}
	bytes_write = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_write == -1)
	{
		free(buffer);
		close(fp);
		return (0);
	}

	close(fp);
	return (bytes_read);
}
