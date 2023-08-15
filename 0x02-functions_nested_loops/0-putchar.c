#include "main.h"

/**
 * main - Print "_putchar"
 * Return: Returns 0
 */
int main(void)
{
	char *putchar = "_putchar\n";

	while (*putchar)
	{
		_putchar(*putchar);
		putchar++;
	}

	return (0);
}
