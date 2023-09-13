#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * main - Performs simple operations (addition, subtraction, multiplication,
 * division or modulo
 * @argc: The number of command line arguments
 * @argv: A pointer to the first command line argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int a = atoi(argv[1]), b = atoi(argv[3]);
	char *op = argv[2];
	int (*op_func)(int, int) = get_op_func(op);
	int result;

	if (argc != 4 || op_func == NULL || ((*op == '/' || *op == '%') && b == 0))
	{
		puts("Error");
		exit((argc != 4) ? 98 : (op_func == NULL) ? 99 : 100);
	}

	result = op_func(a, b);

	printf("%d\n", result);

	return (0);
}
