#include "main.h"

/**
 * copy_file -  copies the content of a file to another file
 * @file_from: source file
 * @file_to: destination file
 * Return: 1-successful
 */

void copy_file(const char *file_from, const char *file_to)
{
	int fd_read, fd_write, fd_stderr = STDERR_FILENO;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	fd_read = open(file_from, O_RDONLY);
	if (fd_read == -1)
	{
		dprintf(fd_stderr, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_write = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_write == -1)
	{
		dprintf(fd_stderr, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	while ((bytes_read = read(fd_read, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read == -1)
		{
			dprintf(fd_stderr, "Error: Can't read from file %s\n", file_from);
			exit(98);
		}
		bytes_written = write(fd_write, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(fd_stderr, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (close(fd_read) == -1)
	{
		dprintf(fd_stderr, "Error: Can't close fd %d\n", fd_read);
		exit(100);
	}
	else
		close(fd_read);

	if (close(fd_write) == -1)
	{
		dprintf(fd_stderr, "Error: Can't close fd %d\n", fd_write);
		exit(100);
	}
	else
		close(fd_write);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: argument array
 * Return: 0 (success), 97-100 (exit value errors)
 */

int main(int argc, const char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
