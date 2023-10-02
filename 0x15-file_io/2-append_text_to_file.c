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
 * append_text_to_file - Appends text to a file.
 *
 * @filename: A pointer to the name of the file
 * @text_content: A pointer to the text to be appended
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written;

	if (filename == NULL)
		return (-1);

	if (access(filename, F_OK) == -1)
		return (-1);

	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	bytes_written = write(fd, text_content, _strlen(text_content));

	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	return (1);
}
