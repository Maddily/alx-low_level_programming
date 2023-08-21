#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: A string
 * Return: An integer
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;

	while (*s < '0' || *s > '9')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		int digit = *s - '0';

		result = (result * 10) + digit;
		s++;
	}
	if (sign == -1)
		return (result * sign);
	else
		return (result);
}
