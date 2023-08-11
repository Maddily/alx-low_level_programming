#include <stdio.h>

/**
  * main - Prints all possible different combinations of two digits
  * Return: Returns 0
  */
int main(void)
{
	int n1 = 0;
	int n2 = 1;

	while (n1 < 9)
	{
		while (n2 <= 9)
		{
			if (n1 == n2)
			{
				n2++;
				continue;
			}
			putchar(n1 + '0');
			putchar(n2 + '0');
			if (n1 == 8 && n2 == 9)
				break;
			putchar(',');
			putchar(' ');
			n2++;
		}
		n1++;
		n2 = n1;
	}
	putchar('\n');
	return (0);
}
