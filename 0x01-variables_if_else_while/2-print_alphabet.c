#include <stdio.h>

/**
  * main - Prints the alphabet in lowercase
  * Return: Returns 0
  */
int main(void)
{
	char ch = 'a';

	while (ch <= 122)
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
