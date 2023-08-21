#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: A string
 */
void puts_half(char *str)
{
	int len = 0;
	char *p = str;

	while (*p != '\0')
	{
		len++;
		p++;
	}
	if (len % 2 == 0)
	{
		p = str + (len / 2);
	}
	else
	{
		p = str + (len + 1) / 2;
	}
	while (*p != '\0')
	{
		_putchar(*p);
		p++;
	}
	_putchar('\n');
}
