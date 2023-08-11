#include <stdio.h>

/**
  * main - Print the alphabet in lowercase and uppercase
  * Return: Returns 0
  */
int main(void)
{
	char lowCh = 'a';
	char upCh = 'A';

	while (lowCh <= 122)
	{
		putchar(lowCh);
		lowCh++;
	}
	while (upCh <= 90)
	{
		putchar(upCh);
		upCh++;
	}
	putchar('\n');
	return (0);
}
