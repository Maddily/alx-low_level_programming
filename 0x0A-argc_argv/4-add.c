#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the sum of positive numbers passed as arguments
 * @argc: The number of arguments in the command line
 * @argv: A pointer to an array of pointers to arguments in the command line
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc < 2)
		printf("%d\n", 0);
	else
	{
		for (i = 1; i < argc; i++)
		{
			if ((!atoi(argv[i]) && *argv[i] !=  '0') ||
					atoi(argv[i]) < 0)
			{
				puts("Error");
				return (1);
			}
			sum += atoi(argv[i]);
		}
		printf("%d\n", sum);
	}

	return (0);
}
