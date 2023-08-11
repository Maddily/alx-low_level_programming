#include <stdio.h>

/**
  * main - Prints all possible different combinations of 3 digits
  * Return: Returns 0
  */
int main(void)
{
	int n1 = 0;
	int n2 = 1;
	int n3 = 2;

	while (n1 < 8)
	{
		while (n2 < 9)
		{
			while (n3 <= 9)
			{
				putchar(n1 + '0');
				putchar(n2 + '0');
				putchar(n3 + '0');
				if (n1 == 7 && n2 == 8 && n3 == 9)
					break;
				putchar(',');
				putchar(' ');
				n3++;
			}
			n2++;
			n3 = n2 + 1;
		}
		n1++;
		n2 = n1 + 1;
		n3 = n2 + 1;
	}
	putchar('\n');
	return (0);
}
