#include "main.h"

/**
 * _strlen - Finds the length of a string
 *
 * @s: A pointer to a string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}
/**
 * create_file - Creates a file
 *
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the text to be added to the file.
 *
 * Return: 1 on success, -1 on failure (if file can't be created, written,
 * or if write fails, or if filename is NULL)
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int bytes_written;

	if (filename == NULL)
		return (-1);

	if (access(filename, F_OK) == -1)
		fd = open(filename, O_CREAT | O_WRONLY, 0600);
	else
		fd = open(filename, O_TRUNC | O_WRONLY);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		bytes_written = write(fd, "", 0);
	else
		bytes_written = write(fd, text_content, _strlen(text_content));
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
