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
	int fdFrom = -1, fdTo = -1, bytesRead, bytesWritten;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdFrom = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) == -1 || fdFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		closeAndCheck(fdFrom, fdTo);
		exit(98);
	}
	if (access(argv[2], F_OK) != -1)
		fdTo = open(argv[2], O_TRUNC | O_WRONLY);
	else
		fdTo = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (fdTo == -1)
		exit99(fdFrom, fdTo, argv[2]);
	while ((bytesRead = read(fdFrom, buffer, sizeof(buffer))) > 0)
	{
		bytesWritten = write(fdTo, buffer, bytesRead);
		if (bytesWritten == -1)
			exit99(fdFrom, fdTo, argv[2]);
	}
	if (bytesRead == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		closeAndCheck(fdFrom, fdTo);
		exit(98);
	}
	closeAndCheck(fdFrom, fdTo);
	return (0);
}

/**
 * exit99 - Exits with a code of 99 if can't write to a file
 *
 * @fdFrom: First file descriptor
 * @fdTo: Second file descriptor
 * @fileTo: The name of the file
 */
void exit99(int fdFrom, int fdTo, char *fileTo)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fileTo);
	closeAndCheck(fdFrom, fdTo);
	exit(99);
}

/**
 * closeAndCheck - Closes file descriptors and checks if it was successful
 *
 * @fdFrom: First file descriptor
 * @fdTo: Second file descriptor
 */
void closeAndCheck(int fdFrom, int fdTo)
{
	int closeFrom, closeTo;

	if (fdFrom != -1)
		closeFrom = close(fdFrom);
	if (fdTo != -1)
		closeTo = close(fdTo);
	if (closeFrom == -1 || closeTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				(closeFrom == -1) ? fdFrom : fdTo);
		exit(100);
	}
}
