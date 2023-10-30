#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * If file does not exist do not create it
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t written_bytes;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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

