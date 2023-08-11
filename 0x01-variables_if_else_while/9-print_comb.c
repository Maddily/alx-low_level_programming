#include <stdio.h>

/**
  * main - Prints 0 to 9
  * Return: Returns 0
  */
int main(void)
{
	int n = 0;

	while (n <= 9)
	{
		putchar(n + '0');
		if (n == 9)
			break;
		putchar(',');
		putchar(' ');
		n++;
	}
	putchar('\n');
	return (0);
}
