#include <stdio.h>

/**
  * main - Prints the alphabet in lowercase except for q and e
  * Return: Returns 0
  */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch != 'q' && ch != 'e')
			putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
