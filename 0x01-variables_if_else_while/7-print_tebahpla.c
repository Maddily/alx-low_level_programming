#include <stdio.h>

/**
  * main - Prints the alphabet in lowercase in reverse
  * Return: Returns 0
  */
int main(void)
{
	char ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);
}
