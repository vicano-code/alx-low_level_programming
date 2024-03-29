#include "main.h"

/**
 * create_file - creates a file with permissions rw---- and writes content
 * If the file already exists, do not change the permissions
 * if the file already exists, truncate it
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t written_bytes;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	written_bytes = write(fd, text_content, strlen(text_content));
	if (written_bytes == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
