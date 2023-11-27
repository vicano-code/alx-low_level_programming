#include "main.h"

/**
 * read_error - print read error to std output
 * @file: source or destination file
 * Return: nothing
 */
void read_error(const char *file)
{
	int fd_stderr = STDERR_FILENO;

	dprintf(fd_stderr, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * write_error - print write error to std output
 * @file: source or destination file
 * Return: nothing
 */
void write_error(const char *file)
{
	int fd_stderr = STDERR_FILENO;

	dprintf(fd_stderr, "Error: Can't write to file %s\n", file);
	exit(99);
}

/**
 * close_error - print close error to std output
 * @fd_val: file descriptor value
 * Return: nothing
 */
void close_error(int fd_val)
{
	int fd_stderr = STDERR_FILENO;

	dprintf(fd_stderr, "Error: Can't close fd %d\n", fd_val);
	exit(100);
}

/**
 * copy_file -  copies the content of a file to another file
 * @file_from: source file
 * @file_to: destination file
 * Return: nothing
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_read, fd_write;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	fd_read = open(file_from, O_RDONLY);
	if (fd_read == -1)
		read_error(file_from);
	fd_write = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_write == -1)
		write_error(file_to);
	while ((bytes_read = read(fd_read, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read == -1)
			read_error(file_from);
		bytes_written = write(fd_write, buffer, bytes_read);
		if (bytes_written == -1)
			write_error(file_to);
	}
	if (close(fd_read) == -1)
		close_error(fd_read);
	else
		close(fd_read);

	if (close(fd_write) == -1)
		close_error(fd_write);
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
