#include <stdio.h>
#include "main.h"

/**
 * main - Prints the number of arguments passed to it
 * @argc: The number of arguments in the command line
 * @argv: A pointer to an array of pointers to arguments in the command line
 * Return: 0
 */
int main(int argc, char *argv[])
{
	UNUSED(argv);
	printf("%d\n", argc - 1);

	return (0);
}
