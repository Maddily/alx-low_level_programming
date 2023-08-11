#include <stdio.h>

/**
  * main - Prints the numbers from 0 to 9
  * Return: Returns 0
  */
int main(void)
{
	char n = '0';

	while (n <= '9')
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
