#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Prints the sum of positive numbers passed as arguments
 * @argc: The number of arguments in the command line
 * @argv: A pointer to an array of pointers to arguments in the command line
 * Return: 0 if successful, 1 if not
 */
int main(int argc, char *argv[])
{
	int i, sum = 0, len;
	char *tmp;

	if (argc < 2)
		printf("%d\n", 0);
	else
	{
		for (i = 1; i < argc; i++)
		{
			tmp = argv[i];
			len = strlen(argv[i]);
			while (len--)
			{
				if ((!atoi(tmp) && *tmp !=  '0') ||
						atoi(tmp) < 0)
				{
					puts("Error");
					return (1);
				}
				tmp++;
			}
			sum += atoi(argv[i]);
		}
		printf("%d\n", sum);
	}

	return (0);
}
