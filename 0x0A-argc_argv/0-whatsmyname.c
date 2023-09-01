#include <stdio.h>
#include "main.h"

/**
 * main - Prints the name of the program
 * @argc: The number of arguments in the command line
 * @argv: A pointer to an array of pointers to arguments in the command line
 * Return: 0
 */
int main(int argc, char *argv[])
{
	UNUSED(argc);
	printf("%s\n", *argv);

	return (0);
}
