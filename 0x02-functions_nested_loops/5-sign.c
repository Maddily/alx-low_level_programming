#include "main.h"

/**
 * print_sign - Prints '+' if n is positive, '0' if 0 and '-' if negative
 * @n: The number whose sign is to be checked
 * Return: Returns 1 if positive, 0 if 0 and -1 if negative
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar(n + '0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
