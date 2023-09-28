#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: A pointer to the string containing a binary number.
 *
 * Return: The converted number or 0. 0 is returned if the string contains
 * characters other than 1 and 0, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	size_t count = 0, i, j;
	unsigned int number = 0;

	if (b == NULL)
		return (0);

	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		count++;
		i++;
	}

	i = count - 1;
	j = 1;

	while (count > 0)
	{
		if (b[i] == '1')
			number += j;
		j *= 2;
		i--;
		count--;
	}

	return (number);
}
