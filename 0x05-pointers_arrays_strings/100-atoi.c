#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: A string
 * Return: An integer
 */
int _atoi(char *s)
{
	int sign = 1, negResult = 0;
	unsigned int posResult = 0;

	while (*s < '0' || *s > '9')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		int digit = *s - '0';

		if (sign == -1)
			negResult = (negResult * 10) + digit;
		else
			posResult = (posResult * 10) + digit;
		s++;
	}
	if (sign == -1)
		return (negResult * sign);
	else
		return (posResult * sign);
}
