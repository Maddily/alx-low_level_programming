#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change
 * for a given amount of money
 * @argc: The number of arguments in the command line
 * @argv: A pointer to an array of pointers to arguments in the command line
 * Return: 0 if successful, 1 if not
 */
int main(int argc, char *argv[])
{
	int i, money, n;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}

	money = atoi(argv[1]);

	if (money < 0)
		printf("%d\n", 0);
	else
	{
		i = 0;
		n = 0;

		while (i < 5)
		{
			if (money >= coins[i])
			{
				n++;
				money -= coins[i];
			}

			if (money < coins[i])
				i++;
		}

		printf("%d\n", n);
	}

	return (0);
}
