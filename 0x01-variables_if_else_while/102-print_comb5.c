#include <stdio.h>

/**
  * main - Prints all possible combinations of 2 2-digit numbers
  * Return: Returns 0
  */
int main(void)
{
	int n1 = 0;
	int n2 = 1;

	while (n1 <= 98)
	{
		while (n2 <= 99)
		{
			if (n1 <= 99)
			{
				putchar((n1 / 10) + '0');
				putchar((n1 % 10) + '0');
			}
			putchar(' ');
			if (n2 <= 99)
			{
				putchar((n2 / 10) + '0');
				putchar((n2 % 10) + '0');
			}
			if (n1 == 98 && n2 == 99)
			{
				break;
			}
			putchar(',');
			putchar(' ');
			if (n1 == 97 && n2 == 99)
			{
				break;
			}
			n2++;
		}
		n1++;
		n2 = n1 + 1;
	}
	putchar('\n');
	return (0);
}
