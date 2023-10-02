#include "main.h"

/**
 * main - Copies the contents of a file into another file
 *
 * @argc: The number of arguments
 * @argv: An array of pointers to arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (access(argv[1], F_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (access(argv[2], F_OK) != -1)
		fd_to = open(argv[2], O_TRUNC | O_WRONLY);
	else
		fd_to = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (fd_to == -1)
		exit_99(fd_from, fd_to, argv[2]);
	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			exit_99(fd_from, fd_to, argv[2]);
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_and_check(fd_from, fd_to);
		exit(98);
	}
	close_and_check(fd_from, fd_to);
	return (0);
}

/**
 * exit_99 - Exits with a code of 99 if can't write to a file
 *
 * @fd_from: First file descriptor
 * @fd_to: Second file descriptor
 * @file_to: The name of the file
 */
void exit_99(int fd_from, int fd_to, char *file_to)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	close_and_check(fd_from, fd_to);
	exit(99);
}

/**
 * close_and_check - Closes file descriptors and checks if it was successful
 *
 * @fd_from: First file descriptor
 * @fd_to: Second file descriptor
 */
void close_and_check(int fd_from, int fd_to)
{
	int close_from, close_to;

	close_from = close(fd_from);
	close_to = close(fd_to);
	if (close_from == -1 || close_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				(close_from == -1) ? fd_from : fd_to);
		exit(100);
	}
}
